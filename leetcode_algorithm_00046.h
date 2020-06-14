/*
No.46:
    Given a collection of distinct integers, return all possible permutations.
&
No.47:
    Given a collection of numbers that might contain duplicates, return all possible unique permutations.
*/

#ifndef __leetcode_algorithm_00046_h__
#define __leetcode_algorithm_00046_h__

#include "basic_headers.h"

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>::size_type cnt = 1;
        for (vector<int>::size_type i = 1; i <= nums.size(); ++i)
            cnt *= i;
        
        vector<vector<int>> result;
        result.reserve(cnt);

        permute(nums, 0, result);
        return result;
    }

    //recursion version~
    vector<vector<int>>::size_type permute(vector<int>& nums, vector<int>::size_type pos, vector<vector<int>>& result) {
        if (pos == nums.size() - 1) {
            result.push_back(vector<int>({ nums[pos] }));
            result.back().reserve(nums.size());
            return 1;
        }
        
        set<int> duplicates;
        vector<vector<int>>::size_type cnt = 0;
        for (auto i = pos; i < nums.size(); ++i) {
            int cur = nums[i];
            if (duplicates.find(cur) != duplicates.end()) {
                continue;
            }

            duplicates.insert(cur);
            swap(nums[pos], nums[i]);
            auto n = permute(nums, pos + 1, result);
            cnt += n;
            auto sz = result.size();
            for (vector<vector<int>>::size_type j = 0; j < n; ++j) {
                result[sz - j - 1].push_back(cur);
            }
            swap(nums[pos], nums[i]);
        }
        return cnt;
    }
};


#endif /*__leetcode_algorithm_00046_h__*/
