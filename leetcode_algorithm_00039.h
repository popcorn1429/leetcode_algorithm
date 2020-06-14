#ifndef __leetcode_algorithm_00039_h__
#define __leetcode_algorithm_00039_h__
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> results;
        vector<int> result;
        combin(target, candidates, 0, candidates.size(), results, result);
        return results;
    }

    void combin(int target, vector<int>& candidates, vector<int>::size_type pos, vector<int>::size_type sz, vector<vector<int>>& results, vector<int>& result) {
        if (target == 0) {
            results.push_back(result);
            return;
        }
        
        if (pos >= sz)
            return;

        int candidate = candidates[pos];
        //part 1: 1+ candidate
        int cnt = 1;
        while (target - candidate*cnt >= 0) {
            result.push_back(candidate);
            combin(target - candidate*cnt, candidates, pos + 1, sz, results, result);
            
            ++cnt;
        }

        //part 2: no candidate
        for (int i = 1; i < cnt; ++i)
            result.pop_back();

        combin(target, candidates, pos + 1, sz, results, result);
    }
};
#endif
