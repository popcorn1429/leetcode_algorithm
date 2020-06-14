#ifndef __leetcode_algorithm_00075_h__
#define __leetcode_algorithm_00075_h__

#include "basic_headers.h"

class Solution {
public:
    void sortColors(vector<int>& nums) {
        if (nums.size() <= 1)
            return;

        vector<int>::size_type zero_pos = 0;
        while (zero_pos < nums.size() && nums[zero_pos] == 0) ++zero_pos;
        if (zero_pos == nums.size()) return;
        vector<int>::size_type two_pos = nums.size() - 1;
        while (two_pos > 0 && nums[two_pos] == 2) --two_pos;
        if (two_pos == 0) return;

        vector<int>::size_type i = zero_pos;
        while (i <= two_pos) {
            if (0 == nums[i]) {
                nums[i] = nums[zero_pos];
                nums[zero_pos] = 0;
                if (2 == nums[i]) {
                    nums[i] = nums[two_pos];
                    nums[two_pos] = 2;
                }
            }
            else if (2 == nums[i]) {
                nums[i] = nums[two_pos];
                nums[two_pos] = 2;
                if (0 == nums[i]) {
                    nums[i] = nums[zero_pos];
                    nums[zero_pos] = 0;
                }
            }

            //update 
            while (zero_pos < nums.size() && nums[zero_pos] == 0) ++zero_pos;
            while (two_pos > 0 && nums[two_pos] == 2) --two_pos;
            if (i < zero_pos)
                i = zero_pos;
            else if (i > two_pos)
                break;
            else
                ++i;
        }
    }
};


#endif /*__leetcode_algorithm_00075_h__*/
