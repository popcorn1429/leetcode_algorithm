#ifndef __leetcode_algorithm_00078_h__
#define __leetcode_algorithm_00078_h__

#include "basic_headers.h"
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> results;
        results.push_back(vector<int>()); // {}
        int n = nums.size();
        for (int k = 1; k <= n; ++k) {
            combine(nums, results, k);
        }
        return results;
    }

    int combine(const vector<int>& nums, vector<vector<int>> &results, int k) {
        int n = nums.size();

        int count_k = 0;
        results.push_back(vector<int>());
        results.reserve(k);
        for (int i = 0; i < k; ++i) {
            results.back().push_back(nums[i]);
            ++count_k;
        }

        vector<int> next;
        do {
            next.reserve(k);
            if (getNext(nums, results.back(), next)) {
                results.push_back(vector<int>());
                ++count_k;
                results.back().swap(next);
            }
            else {
                break;
            }
        } while (true);
        return count_k;
    }

    bool getNext(const vector<int>& nums, const vector<int> &current, vector<int> &next) {
        int n = nums.size();
        //current is the last sequence
        if (current.front() == nums[n-current.size()]) {
            return false;
        }

        int pos = current.size() - 1;
        while (nums[n - (current.size()-pos)] == current[pos]) {
            --pos;
        }

        

        for (int i = 0; i < pos; ++i) {
            next.push_back(current[i]);
        }

        int pos_nums = n - (current.size() - pos);
        while (nums[pos_nums] != current[pos])
            --pos_nums;

        for (int i = pos; i < current.size(); ++i) {
            next.push_back(nums[pos_nums+1+i-pos]);
        }
        return true;
    }

    void printCombinations(const vector<vector<int>> &results) {
        cout << "All sequences are: " << endl;
        for (const auto &sequence : results) {
            cout << "[ ";
            for (int i : sequence) {
                cout << setw(2) << i << " ";
            }
            cout << "]" << endl;
        }
        cout << endl;
    }
};


#endif /*__leetcode_algorithm_00078_h__*/
