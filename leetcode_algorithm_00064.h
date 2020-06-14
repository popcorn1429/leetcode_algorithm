/*
Input:
[
 [1,3,1],
 [1,5,1],
 [4,2,1]
]
Output: 7
Explanation: Because the path 1¡ú3¡ú1¡ú1¡ú1 minimizes the sum.
*/
#ifndef _leetcode_algorithm_00064_h_
#define _leetcode_algorithm_00064_h_
#include "basic_headers.h"

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        size_t m = grid.size();
        if (0 == m)
            return 0;
        size_t n = grid[0].size();
        if (0 == n)
            return 0;

        for (int i = m - 2; i >= 0; --i)
            grid[i][n - 1] += grid[i + 1][n - 1];
        for (int j = n - 2; j >= 0; --j)
            grid[m - 1][j] += grid[m - 1][j + 1];

        for (int i = m - 2; i >= 0; --i) {
            for (int j = n - 2; j >= 0; --j) {
                grid[i][j] += min(getValue(grid, m, n, i+1, j),
                    getValue(grid, m, n, i, j+1));
            }
        }

        return grid[0][0];
    }

    int getValue(const vector<vector<int>>& grid, size_t m, size_t n, int i, int j) {
        if (m <= i || n <= j)
            return INT_MAX;
        else
            return grid[i][j];
    }
};

#endif /*_leetcode_algorithm_00064_h_*/
