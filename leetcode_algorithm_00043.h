#pragma once
#include "basic_headers.h"

class Solution {
public:
    string multiply(string num1, string num2) {
        reverse(num1);
        reverse(num2);
        if (num1.size() >= num2.size()) {
            int sz = num2.size();
            string result;
            string temp;
            for (int i = 0; i < sz; ++i) {
                string res;
                multiply(num1, num2[i], i, res);
                plus(result, res, temp);
                result = temp;
                temp.clear();
            }

            reverse(result);
            return result;
        }
        else {
            int sz = num1.size();
            string result;
            string temp;
            for (int i = 0; i < sz; ++i) {
                string res;
                multiply(num2, num1[i], i, res);
                plus(result, res, temp);
                result = temp;
                temp.clear();
            }

            reverse(result);
            return result;
        }
    }

    void reverse(string& num) {
        int sz = num.size();
        for (int i = 0; i < sz / 2; ++i) {
            swap(num[i], num[sz - 1 - i]);
        }
    }

    void multiply(const string& num1, char c, int n, string& res) {
        if (c == '0') {
            res = "0";
            return;
        }

        for (int i = 0; i < n; ++i)
            res.push_back('0');

        if (c == '1') {
            res.append(num1);
            return;
        }

        int v = 0;
        for (int i = 0; i < num1.size(); ++i) {
            res.push_back(digit_multiply(num1[i], c, v));
        }
        if (v != 0) {
            res.push_back(v + '0');
        }
    }

    void plus(const string& num1, const string& num2, string& sum) {
        int i = 0;
        int j = 0;
        int v = 0;
        while (i < num1.size() || j < num2.size()) {
            char m = i < num1.size() ? num1[i] : '0';
            char n = j < num2.size() ? num2[j] : '0';
            char c = digit_plus(m, n, v);
            sum.push_back(c);
            ++i;
            ++j;
        }
        if (v != 0) {
            sum.push_back(v + '0');
        }
    }

    char digit_plus(char n1, char n2, int& v) {
        int i = n1 - '0';
        int j = n2 - '0';
        int sum = i + j + v;
        if (sum >= 10) {
            v = 1;
            return sum - 10 + '0';
        }
        else {
            v = 0;
            return sum + '0';
        }
    }

    char digit_multiply(char n1, char n2, int& v) {
        int i = n1 - '0';
        int j = n2 - '0';
        int res = i * j + v;
        v = res / 10;
        return res % 10 + '0';
    }
};