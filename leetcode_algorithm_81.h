#ifndef __leetcode_algorithm_81_h__
#define __leetcode_algorithm_81_h__

#include "basic_headers.h"

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if (nums.empty())
            return false;

        //1 get the real first number's position
        int first_pos = getRealStart(nums);

        //2 b-search the target number
        return exists(nums, first_pos, target);
    }

    int getRealStart(const vector<int> &nums) {
        int cnt = nums.size();
        int left_edge_number = nums[0];
        int right_edge_number = nums[cnt - 1];

        //special case: it's already a sorted sequence.
        if (left_edge_number < right_edge_number)
            return 0;

        if (left_edge_number == right_edge_number) {
            return getRealStartWithEqualEdge(nums, left_edge_number, cnt);
        }
        else { //right_edge_number < left_edge_number
            return getRealStartWithBiggerLeft(nums, left_edge_number, right_edge_number, cnt);
        }
    }

    int getRealStartWithEqualEdge(const vector<int> &nums, int edge_number, int cnt) {
        int start_pos = 0;
        int end_pos = cnt;
        int middle_pos = start_pos;
        while (2 < end_pos - start_pos) {
            middle_pos = (start_pos + end_pos) / 2;
            int current_number = nums[middle_pos];
            if (current_number == edge_number) {
                //bad news~ 
                return getRealStartByLinearSearch(nums, cnt);
            }
            
            if (edge_number < current_number) {
                start_pos = middle_pos + 1;
            }
            else {
                end_pos = middle_pos + 1;
            }
        }

        return (2 == end_pos - start_pos && nums[start_pos + 1] < nums[start_pos]) ? start_pos + 1 : start_pos;
    }

    int getRealStartByLinearSearch(const vector<int> &nums, int cnt) {
        for (int i = 0; i < cnt-1; ++i) {
            if (nums[i] > nums[i + 1])
                return i+1;
        }
        return 0;
    }

    int getRealStartWithBiggerLeft(const vector<int> &nums, int left_edge_number, int right_edge_number, int cnt) {
        int start_pos = 0;
        int end_pos = cnt;
        int middle_pos = start_pos;
        while (2 < end_pos - start_pos) {
            middle_pos = (start_pos + end_pos) / 2;
            int current_number = nums[middle_pos];
            if (current_number <= right_edge_number) {
                end_pos = middle_pos + 1;
            }
            else if (current_number < left_edge_number) {
                return -1; //impossible!
            }
            else {
                start_pos = middle_pos + 1;
            }
        }

        return (2 == end_pos - start_pos && nums[start_pos + 1] < nums[start_pos]) ? start_pos + 1 : start_pos;
    }

    bool exists(const vector<int> &nums, int first_pos, int target) {
        int cnt = nums.size();
        int start_pos = first_pos;
        int end_pos = start_pos + cnt;
        while (1 < end_pos - start_pos) {
            int offset_middle_pos = (start_pos + end_pos) / 2;
            int middle_pos = offset_middle_pos % cnt;
            if (nums[middle_pos] == target)
                return true;

            if (nums[middle_pos] < target) {
                start_pos = offset_middle_pos + 1;
            }
            else {
                end_pos = offset_middle_pos;
            }
        }

        start_pos %= cnt;
        return (nums[start_pos] == target);
    }

    string toString(const vector<int> &nums) const {
        string desc;
        for (int i : nums) {
            desc += ' ';
            desc += std::to_string(i);
        }
        return desc;
    }
    void printSequence(const vector<int> &nums) {
        cout << "[ ";
        for (int i : nums) {
            cout << i << " ";
        }
        cout << "]" << endl;
    }
};

#endif /*__leetcode_algorithm_81_h__*/
