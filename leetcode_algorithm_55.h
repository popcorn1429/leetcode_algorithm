/*
55. Jump Game
Given an array of non-negative integers, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Determine if you are able to reach the last index.
*/

#ifndef _leetcode_algorithm_55_h_
#define _leetcode_algorithm_55_h_
#include "basic_headers.h"

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int curPos = nums.size() - 1;
        
        while (true) {
            curPos = previousStep(nums, curPos);
            if (0 == curPos)
                return true;
            if (-1 == curPos)
                return false;
        }
        return false;
    }

    int previousStep(const vector<int>& nums, int curPos) {
        if (curPos == 0)
            return 0;

        for (int i = 1; i <= curPos; ++i) {
            if (0 <= nums[curPos - i] - i)
                return curPos - i;
        }

        return -1;
    }
};

#endif /*_leetcode_algorithm_55_h_*/