#pragma once
#include "basic_headers.h"

class Solution {
public:
    string convertToTitle(int n) {
        string result;
        while (n > 0) {
            int r = n % 26;
            if (r != 0) {
                result += (char('A' + r - 1));
            }
            else {
                result += ('Z');
                n -= 26;
            }
            n /= 26;
        }
        return reversed(result);
    }

    string reversed(const string &str) {
        string result;
        for (int i = str.size() - 1; i >= 0; --i) {
            result += (str[i]);
        }
        return result;
    }
};