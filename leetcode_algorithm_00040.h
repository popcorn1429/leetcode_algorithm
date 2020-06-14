#ifndef __leetcode_algorithm_00040_h__
#define __leetcode_algorithm_00040_h__
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> results;
        vector<int> result;

        sort(candidates.begin(), candidates.end());
        combin(target, candidates, 0, candidates.size(), results, result);
        return results;
    }

    void combin(int target, vector<int>& candidates, vector<int>::size_type pos, vector<int>::size_type sz, vector<vector<int>>& results, vector<int>& result) {
        if (target == 0) {
            if (find(results.begin(), results.end(), result) == results.end())
                results.push_back(result);
            return;
        }

        if (pos >= sz)
            return;

        int candidate = candidates[pos];
        //part 1: contains candidate
        if (target - candidate >= 0) {
            result.push_back(candidate);
            combin(target - candidate, candidates, pos + 1, sz, results, result);
            result.pop_back();
        }

        //part 2: exclude candidate
        combin(target, candidates, pos + 1, sz, results, result);
    }
};
#endif
