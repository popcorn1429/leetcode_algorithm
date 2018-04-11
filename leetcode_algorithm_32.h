#ifndef __leetcode_algorithm_32_h__
#define __leetcode_algorithm_32_h__
#include <string>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        string::size_type sz = s.size();
        if (sz <= 1)
            return 0;

        modify(s);

        int max_len = 0;
        int cur_len = 0;
        int cur_calc = 0;
        for (int pos = sz-1; pos >= 0; --pos) {
            if (s[pos] == '.') {
                if (max_len < cur_len) {
                    max_len = cur_len;
                }
                cur_len = 0;
            }
            else if ('(' == s[pos]) {
                if (cur_calc > 0) {
                    ++cur_len;
                    --cur_calc;
                }
                else {
                    if (max_len < cur_len) {
                        max_len = cur_len;
                    }
                    cur_len = 0;
                    cur_calc = 0;
                }
            }
            else if (')' == s[pos]) {
                ++cur_len;
                ++cur_calc;
            }
        }

        if (max_len < cur_len)
            max_len = cur_len;

        return max_len;
    }

    void modify(string& s) {
        string::size_type right = 0;
        string::size_type invalid = 0;
        for (string::size_type pos = 0; pos != s.size(); ++pos) {
            if (s[pos] == ')') {
                ++right;
                if (pos + 1 + invalid < right * 2) {
                    s[pos] = '.';
                    ++invalid;
                }
            }
        }
    }
};

#endif