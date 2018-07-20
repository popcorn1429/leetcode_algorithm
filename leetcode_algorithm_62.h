/*
Example 1:
Input: m = 3, n = 2
Output: 3
Explanation:
From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Right -> Down
2. Right -> Down -> Right
3. Down -> Right -> Right

Example 2:

Input: m = 7, n = 3
Output: 28

*/

#ifndef _leetcode_algorithm_62_h_
#define _leetcode_algorithm_62_h_
#include "basic_headers.h"
class Solution {
public:
    //quite slow when m & n is big
    int uniquePaths_recursion(int m, int n) {
        if (n == 1 || m == 1)
            return 1;

        return uniquePaths_recursion(m - 1, n) + uniquePaths_recursion(m, n - 1);
    }

    //based on uniquePaths_recursion
    //add a vector to save tmp result
    //fast enough, good solution.
    int uniquePaths_fast(int m, int n) {
        if (n == 1 || m == 1)
            return 1;

        static vector<vector<int>> aux(m, vector<int>(n, 0));
        int r1 = (0 < aux[m - 2][n - 1]) ? aux[m - 2][n - 1] : uniquePaths_fast(m - 1, n);
        int r2 = (0 < aux[m - 1][n - 2]) ? aux[m - 1][n - 2] : uniquePaths_fast(m, n - 1);
        aux[m - 2][n - 1] = r1;
        aux[m - 1][n - 2] = r2;
        return r1 + r2;
    }

    //as fast as uniquePaths_fast
    //quite clean and clear, it's the best solution!
    //though it's not my solution ~~ but it's realy good.
    int uniquePaths_perfect(int m, int n) {
        vector<vector<int>> paths(m, vector<int>(n));
        paths[0][0] = 1; // init

        for (size_t i = 1; i < m; i++) { paths[i][0] += paths[i - 1][0]; } // first row update
        for (size_t j = 1; j < n; j++) { paths[0][j] += paths[0][j - 1]; } // first col update

        for (size_t i = 1; i < m; i++) {
            for (size_t j = 1; j < n; j++) {
                paths[i][j] += paths[i - 1][j] + paths[i][j - 1];
            }
        }
        return paths[m - 1][n - 1];
    }

    //my
    int uniquePaths(int m, int n) {
        vector<vector<int>> aux(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i)
            aux[i][0] = 1;
        for (int i = 0; i < n; ++i)
            aux[0][i] = 1;

        for (int i = 1; i < m; ++i)
        for (int j = 1; j < n; ++j)
            aux[i][j] = aux[i - 1][j] + aux[i][j - 1];

        return aux[m - 1][n - 1];
    }
};


#endif /*_leetcode_algorithm_62_h_*/