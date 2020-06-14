#pragma once
#include "basic_headers.h"

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() <= 1)
            return s.size();

        int max = 0;
        int start = 0;
        for (int i = 1; i < s.size(); ++i) {
            char c = s.at(i);
            bool duplicate = false;
            int dup_pos = -1;
            for (int j = start; j < i; ++j) {
                if (s[j] == c) {
                    duplicate = true;
                    dup_pos = j;
                    break;
                }
            }

            if (duplicate) {
                if (max < i - start)
                    max = i - start;

                start = dup_pos + 1;
            }
        }

        if (max < s.size() - start)
            max = s.size() - start;

        return max;
    }
};
