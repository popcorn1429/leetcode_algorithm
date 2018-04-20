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
    //����ⷨ�ǿ��˱��˵Ĵ𰸣�Ȼ��һ���Ķ����֮�󳭵�
    //��Ҫ�������Ǹ�if����˼�������������Ϊʲô����ȷ��
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