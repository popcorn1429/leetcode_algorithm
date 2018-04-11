#ifndef __leetcode_algorithm_16_h__
#define __leetcode_algorithm_16_h__
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        auto sz = nums.size();
        if (sz < 3)
            return 0;

        sort(nums.begin(), nums.end());
        //special case
        if (target < nums[0] + nums[1] + nums[2]) {
            return nums[0] + nums[1] + nums[2];
        }
        else if (nums[sz - 1] + nums[sz - 2] + nums[sz - 3] < target) {
            return nums[sz - 1] + nums[sz - 2] + nums[sz - 3];
        }

        unsigned min_dis = UINT_MAX;
        int      closest_sum = INT_MAX;
        for (vector<int>::size_type i = 0; i < nums.size(); ++i) {
            int first = nums[i];

            for (vector<int>::size_type j = nums.size() - 1; j > i; --j) {
                int third = nums[j];
                int ideal_second = target - first - third;

                if (ideal_second > third) {
                    //the best second must in pos[ j-1 ]
                    auto dis = calcDistance(nums, j - 1, ideal_second);
                    if (dis < min_dis) {
                        min_dis = dis;
                        closest_sum = first + nums[j - 1] + third;
                    }
                    break;
                }

                //the best second is between pos[i] and pos[j]
                auto pos = binary_fuzzy_search(nums, i, j, ideal_second);
                if (pos != i) {
                    auto dis = calcDistance(nums, pos, ideal_second);
                    if (dis < min_dis) {
                        min_dis = dis;
                        closest_sum = first + nums[pos] + third;
                    }
                }
                
                if (pos + 1 != j) {
                    auto dis = calcDistance(nums, pos + 1, ideal_second);
                    if (dis < min_dis) {
                        min_dis = dis;
                        closest_sum = first + nums[pos + 1] + third;
                    }
                }
            }
        }

        return closest_sum;
    }

    unsigned calcDistance(const vector<int>& nums, const vector<int>::size_type pos, int ideal) {
        unsigned distance = UINT_MAX;
        if (pos >= 0 && pos < nums.size()) {
            distance = nums[pos] < ideal ? ideal - nums[pos] : nums[pos] - ideal;
        }
        return distance;
    }

    template <typename T>
    typename vector<T>::size_type binary_fuzzy_search(const vector<T>& nums, typename vector<T>::size_type begin_pos, typename vector<T>::size_type end_pos, const T& value) {
        if (begin_pos == end_pos)
            return begin_pos;

        if (end_pos - begin_pos == 1)
            return begin_pos;

        auto middle_pos = (begin_pos + end_pos) / 2;
        if (nums[middle_pos] <= value) {
            if (middle_pos + 1 < end_pos) {
                if (value <= nums[middle_pos + 1])
                    return middle_pos;
                else
                    return binary_fuzzy_search(nums, middle_pos + 1, end_pos, value);
            }
            else {
                return middle_pos;
            }
        }
        else {
            if (begin_pos <= middle_pos - 1) {
                if (nums[middle_pos - 1] <= value)
                    return middle_pos - 1;
                else
                    return binary_fuzzy_search(nums, begin_pos, middle_pos, value);
            }
            else {
                return begin_pos;
            }
        }
    }
};
#endif