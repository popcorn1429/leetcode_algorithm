#ifndef __leetcode_algorithm_33_h__
#define __leetcode_algorithm_33_h__
#include <vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) {
            return -1;
        }
        else if (nums.size() == 1) {
            if (target != nums[0])
                return -1;
            else
                return 0;
        }

        //1 find the real begin
        vector<int>::size_type begin_pos = findBeginPos(nums);

        //2 find the value 
        vector<int>::size_type sz = nums.size();
        vector<int>::size_type low = 0;
        vector<int>::size_type high = sz - 1;
        vector<int>::size_type pos = (low + high) / 2;
        while (nums[(begin_pos + pos) % sz] != target && high - low != 0) {
            if (nums[(begin_pos + pos) % sz] < target) {
                low = pos+1;
            }
            else {
                high = pos;
            }
            pos = (low + high) / 2;
        }

        if (nums[(pos + begin_pos) % sz] != target)
            return -1;
        else
            return (pos + begin_pos) % sz;
    }

    vector<int>::size_type findBeginPos(vector<int>& nums) {
        vector<int>::size_type low = 0;
        vector<int>::size_type high = nums.size()-1;
        if (nums[low] <= nums[high])
            return low;

        vector<int>::size_type mid = (low + high) / 2;
        while (high - low != 1) {
            if (nums[low] < nums[mid])
                low = mid;
            else
                high = mid;

            mid = (low + high) / 2;
        }

        return high;
    }
};
#endif