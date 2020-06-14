#ifndef __leetcode_algorithm_00080_h__
#define __leetcode_algorithm_00080_h__

#include "basic_headers.h"

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 2)
            return nums.size();
        int dest_pos = 0;
        int current_num = nums[0];
        int repeat_time = 0;
        for (int check_pos = 0; check_pos != nums.size(); ++check_pos) {
            if (current_num != nums[check_pos]) {
                current_num = nums[check_pos];
                repeat_time = 1;
            }
            else {
                ++repeat_time;
            }

            if (repeat_time <= 2) {
                if (dest_pos != check_pos)
                    nums[dest_pos] = nums[check_pos];

                ++dest_pos;
            }
        }
        return dest_pos;
    }
};

#endif /*__leetcode_algorithm_80_h__*/
