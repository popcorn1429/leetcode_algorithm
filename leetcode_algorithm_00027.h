#ifndef __leetcode_algorithm_00027_h__
#define __leetcode_algorithm_00027_h__
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.empty())
            return 0;

        auto sz = nums.size();
        vector<int>::size_type cur = 0;
        
        for (vector<int>::size_type pos = 0; pos != sz; ++pos) {
            if (nums[pos] != val) {
                if (pos != cur) {
                    nums[cur] = nums[pos];
                    nums[pos] = val;
                }
                ++cur;
            }
        }
        return cur;
    }
};
#endif
