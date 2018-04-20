/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Your goal is to reach the last index in the minimum number of jumps.
*/

#ifndef __leetcode_algorithm_45_h__
#define __leetcode_algorithm_45_h__
#include <vector>
using namespace std;

class Solution {
public:
    //这个解法是看了别人的答案，然后一番阅读理解之后抄的
    //需要搞明白那个if的意思，才能理解这样为什么是正确的
    int jump(vector<int>& nums) {
        int steps = 0;
        int laststepmax = 0;
        int max = 0;
        for (auto i = 0; i < nums.size()-1; ++i) {
            max = (max < i + nums[i]) ? (i + nums[i]) : max;
            if (i == laststepmax) {
                ++steps;
                laststepmax = max;
            }
        }

        return steps;
    }
};
#endif