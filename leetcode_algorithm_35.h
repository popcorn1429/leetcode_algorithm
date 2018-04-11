#ifndef __leetcode_algorithm_35_h__
#define __leetcode_algorithm_35_h__
#include <vector>
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.empty())
            return 0;

        int sz = nums.size();
        int low = 0;
        int high = sz - 1;
        int mid = 0;
        while (low <= high) {
            mid = (low + high) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        if (nums[mid] < target)
            return mid + 1;
        else
            return mid;
    }
};
#endif