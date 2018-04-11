#ifndef __leetcode_algorithm_34_h__
#define __leetcode_algorithm_34_h__
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty())
            return {-1,-1};

        int sz = nums.size();
        int low = 0;
        int high = sz - 1;
        int pos = (low + high) / 2;

        do {
            if (nums[pos] == target) {
                int begin_pos = getBeginPos(nums, low, pos, target);
                int end_pos = getEndPos(nums, pos, high, target);
                return {begin_pos, end_pos};
            }
            else if (nums[pos] < target) {
                low = pos + 1;
            }
            else {
                high = pos - 1;
            }

            pos = (low + high) / 2;
        } while (low <= high);

        return { -1, -1 };
    }

    int getBeginPos(const vector<int>& nums, int low, int pos, int target) {
        if (nums[low] == target)
            return low;

        int mid = (pos + low) / 2;
        while (!(nums[mid] != target && nums[mid + 1] == target)) {
            if (nums[mid] == target) {
                pos = mid;
            }
            else {
                low = mid;
            }

            mid = (pos + low) / 2;
        }

        return mid + 1;
    }

    int getEndPos(const vector<int>& nums, int pos, int high, int target) {
        if (nums[high] == target)
            return high;
        
        int mid = (pos + high) / 2;
        while (!(nums[mid] == target && nums[mid + 1] != target)) {
            if (nums[mid] == target) {
                pos = mid;
            }
            else {
                high = mid;
            }

            mid = (pos + high) / 2;
        }

        return mid;
    }
};

#endif