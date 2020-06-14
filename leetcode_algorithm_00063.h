/*

Now consider if some obstacles are added to the grids. How many unique paths would there be?
Input:
[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
Output: 2
Explanation:
There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right

*/
#ifndef __leetcode_algorithm_00063_h__
#define __leetcode_algorithm_00063_h__
#include "basic_headers.h"

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        size_t m = obstacleGrid.size();
        if (m == 0) {
            return 0;
        }
        size_t n = obstacleGrid[0].size();
        if (n == 0) {
            return 0;
        }

        vector<vector<int>> aux(m, vector<int>(n, 0));
        initEdge(obstacleGrid, m, n, aux);

        for (int i = m - 2; i >= 0; --i) {
            for (int j = n - 2; j >= 0; --j) {
                if (1 == obstacleGrid[i][j]) {
                    aux[i][j] = 0;
                }
                else {
                    aux[i][j] = aux[i + 1][j] + aux[i][j + 1];
                }
            }
        }

        return aux[0][0];
    }

    void initEdge(const vector<vector<int>> &obstacleGrid, size_t m, size_t n, vector<vector<int>> &aux) {
        bool blocked = false;
        for (int i = m - 1; i >= 0; --i) {
            if (blocked)
                aux[i][n - 1] = 0;
            else {
                if (1 == obstacleGrid[i][n - 1]) {
                    blocked = true;
                    aux[i][n - 1] = 0;
                }
                else {
                    aux[i][n - 1] = 1;
                }
            }
        }

        blocked = false;
        for (int i = n - 1; i >= 0; --i) {
            if (blocked)
                aux[m - 1][i] = 0;
            else {
                if (1 == obstacleGrid[m - 1][i]) {
                    blocked = true;
                    aux[m - 1][i] = 0;
                }
                else
                    aux[m - 1][i] = 1;
            }
        }
    }
};

#endif /*__leetcode_algorithm_00063_h__*/
