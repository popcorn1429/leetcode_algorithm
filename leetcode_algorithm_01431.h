#pragma once
#include "basic_headers.h"

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> result(candies.size(), false);
        if (candies.empty()) return result;
        int _max = candies[0];
        candies[0] = 0;

        for (int i = 1; i < candies.size(); ++i) {
            if (_max < candies[i]) {
                int offset = candies[i] - _max;
                _max = candies[i];
                for (int j = 0; j < i; ++j) {
                    candies[j] += offset;
                }
                candies[i] = 0;
            }
            else {
                candies[i] = _max - candies[i];
            }
        }

        for (int i = 0; i < candies.size(); ++i) {
            if (candies[i] <= extraCandies) {
                result[i] = true;
            }
        }
        return result;
    }
};