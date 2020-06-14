#pragma once
#include "basic_headers.h"

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        if (1 == nums.size()) return nums[0];
        vector<int> yields(nums.size(), 0);
        yields[0] = nums[0];
        yields[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); ++i) {
            yields[i] = (max(yields[i - 1], yields[i - 2] + nums[i]));
        }
        return yields[nums.size() - 1];
    }
};