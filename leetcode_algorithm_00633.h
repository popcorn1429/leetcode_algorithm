#pragma once
#include "basic_headers.h"

class Solution {
public:
    bool judgeSquareSum(int c) {
        static vector<int> squares;
        size_t sz = squares.size();

        if (sz * sz <= c) {
            size_t i = sz;
            while (i * i <= c) {
                squares.push_back(i*i);
                ++i;
            }
        }

        for (size_t i = 0; i < squares.size(); ++i) {
            if (binary_search(squares, 0, squares.size(), c - squares[i]))
                return true;
        }
        return false;
    }

    bool binary_search(vector<int> &squares, size_t start, size_t end, int val) {
        if (end <= start) return false;
        if (val == squares[start]) return true;
        if (val < squares[start]) return false;

        if (val == squares[end - 1]) return true;
        if (squares[end - 1] < val) return false;

        size_t mid = (end + start) / 2;
        if (squares[mid] == val) return true;
        if (squares[mid] < val) return binary_search(squares, mid, end, val);
        else return binary_search(squares, start, mid, val);
    }


    /////////////
    bool judgeSquareSum2(int c) {
        long left = 0;
        long right = (int)sqrt(c);

        while (left <= right) {
            long n = left * left + right * right;
            if (n == c) return true;
            else if (n < c) ++left;
            else --right;
        }
        return false;
    }

    ///////////////
    bool judgeSquareSum3(int c) {
        long left = 0;
        long right = (long)sqrt(c);

        while (left <= right) {
            long n = left * left + right * right;
            if (n == c) return true;
            else if (n < c) ++left;
            else --right;
        }
        return false;
    }
};