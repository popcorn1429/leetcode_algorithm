#ifndef __leetcode_algorithm_45_h__
#define __leetcode_algorithm_45_h__
#include <vector>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() <= 1)
            return 0;

        int target = nums.size() - 1;
        int steps = 1;
        while (true) {
            target = jump_aux(nums, target);
            if (target != 0)
                ++steps;
            else
                break;
        }
        return steps;
    }

    int jump_aux(const vector<int>& nums, int target) {
        for (size_t i = 0; i < nums.size(); ++i) {
            if (i + nums[i] >= target)
                return i;
        }
        return target;
    }
};
#endif