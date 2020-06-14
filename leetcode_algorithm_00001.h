#pragma once
#include "basic_headers.h"

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> pair;

        map<int, int> others;
        for (int i = 0; i < nums.size(); ++i) {
            int other = target - nums[i];
            auto iter = others.find(other);
            if (iter != others.end()) {
                pair.push_back(iter->second);
                pair.push_back(i);
                return pair;
            }
            else
            {
                others.insert(std::pair<int, int>(nums[i], i));
            }
        }
        return pair;
    }
};