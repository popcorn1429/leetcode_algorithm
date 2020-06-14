#ifndef __leetcode_algorithm_00031_h__
#define __leetcode_algorithm_00031_h__
#include <vector>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        auto sz = nums.size();
        if (sz <= 1)
            return;

        vector<int>::size_type pos = 0;
        for (vector<int>::size_type i = 1; i < nums.size(); ++i){
            if (nums[i] > nums[i - 1]) {
                pos = i;
            }
        }

        if (pos == 0) {
            reverse(nums, 0, sz-1);
            return;
        }

        int exchange_left = nums[pos - 1];
        vector<int>::size_type exchange_right_pos = pos;
        for (vector<int>::size_type i = pos + 1; i < sz; ++i) {
            if (nums[i] > exchange_left) {
                exchange_right_pos = i;
            }
        }

        nums[pos - 1] = nums[exchange_right_pos];
        nums[exchange_right_pos] = exchange_left;
        reverse(nums, pos, sz - 1);
        return;
    }

    void reverse(vector<int>& nums, vector<int>::size_type begin_pos, vector<int>::size_type end_pos) {
        auto sum = begin_pos + end_pos;
        vector<int>::size_type half_pos = sum / 2;

        for (vector<int>::size_type i = begin_pos; i <= half_pos; ++i) {
            int tmp = nums[i];
            nums[i] = nums[sum - i];
            nums[sum - i] = tmp;
        }
    }
};

#endif
