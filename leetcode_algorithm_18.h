#ifndef __leetcode_algorithm_18_h__
#define __leetcode_algorithm_18_h__
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        auto sz = nums.size();
        if (sz < 4)
            return vector<vector<int>>();

        sort(nums.begin(), nums.end());

        vector<vector<int>> result;
        vector<int> combo{0,0,0,0};
        getCombo(nums, sz, 0, combo, 4, 0, target, result);

        return result;
    }

    //not used
    void distinct(vector<int>& nums, const vector<int>::size_type sz) {
        if (sz <= 1)
            return;

        vector<int>::size_type insert_index = 1;
        vector<int>::size_type pos = 1;
        int last_value = nums[0];
        for (; pos != sz; ++pos) {
            if (last_value != nums[pos]) {
                if (pos != insert_index) {
                    nums[insert_index] = nums[pos];
                    last_value = nums[insert_index];
                    ++insert_index;
                }
            }
        }
        nums.resize(insert_index);
    }

    void getCombo(const vector<int>& nums, const vector<int>::size_type sz, const vector<int>::size_type begin_pos, 
        vector<int>& combo, const unsigned combo_size, unsigned cur_index,
        int target, vector<vector<int>>& result) {

        if (cur_index == combo_size - 1) {
            auto pos = binary_search(nums, sz, begin_pos, sz, target);
            if (pos != sz) {
                combo[cur_index] = nums[pos];
                if (find(result.begin(), result.end(), combo) == result.end())
                    result.push_back(combo);
            }
        }
        else {
            for (vector<int>::size_type pos = begin_pos; pos <= sz - combo_size + cur_index; ++pos) {
                combo[cur_index] = nums[pos];
                auto new_target = target - combo[cur_index];
                getCombo(nums, sz, pos + 1, combo, combo_size, cur_index + 1, new_target, result);
            }
        }
    }

    vector<int>::size_type binary_search(const vector<int>& nums, const vector<int>::size_type sz, const vector<int>::size_type begin_pos, const vector<int>::size_type end_pos, int target) {
        if (begin_pos == end_pos)
            return sz;

        auto middle_pos = (end_pos + begin_pos) / 2;
        int  middle = nums[middle_pos];
        if (middle == target)
            return middle_pos;
        else if (middle < target)
            return binary_search(nums, sz, middle_pos + 1, end_pos, target);
        else
            return binary_search(nums, sz, begin_pos, middle_pos, target);
    }
};

#endif