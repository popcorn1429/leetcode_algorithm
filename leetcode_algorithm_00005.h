#ifndef _leetcode_algorithm_00005_h_
#define _leetcode_algorithm_00005_h_
/*
Given a string s, find the longest palindromic substring in s.
You may assume that the maximum length of s is 1000.

example:
Input: "babad"
Output: "bab"  or   "aba"
*/
#include <string>
#include <cstdio>
#include <iostream>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() <= 1)
            return s;

        string::size_type pos = 0;
        string::size_type length = 1;
        auto n = s.size();
        for (decltype(n) i = 1; i <= n - 1; ++i) {
            if (s[i] == s[i - 1]) {
                auto j = 1U;
                auto l = 2U;
                while ((i + j < n && i - 1 - j >= 0) && (s[i + j] == s[i - 1 - j])) {
                    l += 2;
                    ++j;
                }
                if (l > length) {
                    pos = i;
                    length = l;
                }
            }

            if (s[i - 1] == s[i + 1]) {
                auto j = 1U;
                auto l = 3U;
                while ((i - 1 - j >= 0 && i + 1 + j < n) && (s[i - 1 - j] == s[i + 1 + j])) {
                    l += 2;
                    ++j;
                }
                if (l > length) {
                    pos = i;
                    length = l;
                }
            }
        }

        return s.substr(pos - length / 2, length);
    }
};


#endif /*_leetcode_algorithm_5_h_*/
