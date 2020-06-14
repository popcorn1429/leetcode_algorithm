//Your algorithm should run in O(n) time and uses constant space.

#pragma once
#include <vector>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int sz = nums.size();
        for (int i = 0; i < sz; ++i) {
            while (nums[i] > 0 && nums[i] <= sz && nums[i] != 1 + i) {
                if (nums[i] == nums[nums[i] - 1])
                    break;
                swap(nums[i], nums[nums[i]-1]);
            }
        }

        for (int i = 0; i < sz; ++i) {
            if (nums[i] != 1 + i) {
                return 1 + i;
            }
        }
        return sz + 1;
    }
};
