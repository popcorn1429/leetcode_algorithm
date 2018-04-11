#ifndef __leetcode_algorithm_26_h__
#define __leetcode_algorithm_26_h__
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        auto sz = nums.size();
        if (sz <= 1)
            return sz;

        int cur = nums[0];
        vector<int>::size_type curPos = 1;
        for (vector<int>::size_type i = 1; i < sz; ++i) {
            if (nums[i] != cur) {
                cur = nums[i];
                if (i != curPos) {
                    nums[curPos] = cur;
                }
                ++curPos;
            }
        }
        return curPos;
    }
};
#endif