#pragma once
#include "basic_headers.h"

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        map<int, int> elements;
        for (int i = 0; i < nums.size(); ++i) {
            if (elements.find(nums[i]) != elements.end()) {
                ++elements[nums[i]];
            }
            else {
                elements[nums[i]] = 1;
            }
        }

        vector<vector<int>> result;
        result.push_back(vector<int>());

        for (map<int, int>::iterator itr = elements.begin(); itr != elements.end(); ++itr) {
            addNewElement(result, itr->first, itr->second);
        }
        return result;
    }

    void addNewElement(vector<vector<int>> &sets, int num, int count) {
        int nsets = sets.size();
        for (int i = 1; i <= count; ++i) {
            for (int j = 0; j < nsets; ++j) {
                vector<int> subset(sets[j].size() + i, 0);
                makeSubset(subset, sets[j], num, i);
                sets.push_back(subset);
            }
        }
    }

    void makeSubset(vector<int> &subset, const vector<int> &origin, int num, int cnt) {
        subset.resize(origin.size() + cnt);
        for (int i = 0; i < origin.size(); ++i) {
            subset[i] = origin[i];
        }

        for (int i = origin.size(); i < subset.size(); ++i) {
            subset[i] = num;
        }
    }
};