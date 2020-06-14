#pragma once
#include "basic_headers.h"

class Solution {
public:
    bool validPalindrome(string s) {
        if (s.size() <= 1) return true;

        int left = 0;
        int right = s.size() - 1;

        while (left <= right && s[left] == s[right]) {
            ++left;
            --right;
        }

        if (left < right) {
            return symmetric(s, left + 1, right) || symmetric(s, left, right - 1);
        }

        return true;
    }

    bool symmetric(const string &s, int left, int right) {
        while (left <= right) {
            if (s[left] != s[right]) return false;
            ++left;
            --right;
        }
        return true;
    }
};