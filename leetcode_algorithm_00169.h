#pragma once
#include "basic_headers.h"

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = nums[0];
        int supporters = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == candidate) ++supporters;
            else if (supporters == 0) { candidate = nums[i]; supporters = 1; }
            else --supporters;
        }
        return candidate;
    }
};