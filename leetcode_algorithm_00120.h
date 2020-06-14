#pragma once
#include "basic_headers.h"

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.empty()) return 0;
        if (triangle.size() == 1) return triangle[0][0];

        int totalRow = triangle.size();
        for (int row = totalRow - 2; row >= 0; --row) {
            for (int col = 0; col < triangle[row].size(); ++col) {
                triangle[row][col] += (min(triangle[row + 1][col], triangle[row + 1][col + 1]));
            }
        }
        return triangle[0][0];
    }
};