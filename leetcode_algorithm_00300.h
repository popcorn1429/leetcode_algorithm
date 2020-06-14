#pragma once
#include "basic_headers.h"

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> result(nums.size(), 0);
        int max_n = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int n = 1;
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j] && n < result[j] + 1) n = result[j] + 1;
            }
            result[i] = n;

            if (max_n < n) max_n = n;
        }
        return max_n;
    }
};