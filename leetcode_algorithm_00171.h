#pragma once
#include "basic_headers.h"

class Solution {
public:
    int titleToNumber(string s) {
        size_t n = s.size();
        int result = 0;
        for (size_t i = 0; i != n; ++i) {
            result *= 26;
            result += (s[i] - 'A' + 1);
        }
        return result;
    }
};