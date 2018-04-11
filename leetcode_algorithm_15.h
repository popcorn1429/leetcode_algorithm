#ifndef __leetcode_algorithm_15_h__
#define __leetcode_algorithm_15_h__

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        //
        quick_sort(nums, 0, nums.size());
        
        //
        int last_first = INT_MIN;
        int last_third = INT_MAX;
        for (vector<int>::size_type i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0)
                break;

            int first = nums[i];
            for (decltype(i) j = nums.size() - 1; j > i; --j) {
                if (nums[j] < 0 || (first < 0 && nums[j] == 0))
                    break;
                int third = nums[j];
                if (last_first == first && last_third <= third)
                    continue;

                int second = 0 - (first + third);
                auto second_pos = binary_search(nums, i+1, j, second);
                if (second_pos != nums.size()) {
                    last_first = first;
                    last_third = third;
                    result.push_back({ first, second, third });
                }
            }
        }

        return result;
    }

    template <typename T>
    void quick_sort(vector<T>& nums, typename vector<T>::size_type begin_pos, typename vector<T>::size_type end_pos) {
        if (end_pos - begin_pos <= 1)
            return;
        vector<T>::size_type flag_pos = begin_pos;
        const T flag_value = nums[flag_pos];
        decltype(flag_pos) left = flag_pos + 1;
        decltype(flag_pos) right = end_pos - 1;

        while (left <= right) {
            while (left <= right) {
                if (nums[right] < flag_value) {
                    swap(nums, flag_pos, right);
                    flag_pos = right;
                    --right;
                    break;
                }
                --right;
            }

            while (left <= right) {
                if (flag_value < nums[left]) {
                    swap(nums, flag_pos, left);
                    flag_pos = left;
                    ++left;
                    break;
                }
                ++left;
            }
        }
        
        quick_sort(nums, begin_pos, flag_pos);
        quick_sort(nums, flag_pos + 1, end_pos);
    }

    template <typename T>
    void swap(vector<T>& nums, typename vector<T>::size_type first, typename vector<T>::size_type second) {
        auto tmp = nums[first];
        nums[first] = nums[second];
        nums[second] = tmp;
    }

    template <typename T>
    typename vector<T>::size_type binary_search(const vector<T>& nums, typename vector<T>::size_type begin_pos, typename vector<T>::size_type end_pos, const T& value) {
        if (end_pos == begin_pos)
            return nums.size();

        if (end_pos - begin_pos == 1) {
            if (nums[begin_pos] != value)
                return nums.size();
            return begin_pos;
        }

        decltype(begin_pos) middle_pos = begin_pos + (end_pos - begin_pos) / 2;
        if (nums[middle_pos] == value)
            return middle_pos;
        else if (nums[middle_pos] < value)
            return binary_search(nums, middle_pos, end_pos, value);
        else
            return binary_search(nums, begin_pos, middle_pos, value);
    }
};

#endif