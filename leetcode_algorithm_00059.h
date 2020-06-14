/*
Given a positive integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

Example:

Input: 3
Output:
  [
   [ 1, 2, 3 ],
   [ 8, 9, 4 ],
   [ 7, 6, 5 ]
  ]
*/

#ifndef _leetcode_algorithm_00059_h_
#define _leetcode_algorithm_00059_h_
#include "basic_headers.h"

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n,0));
        int half = n / 2;
        for (int row = 0; row < n; ++row) {
            if (n - 2 * row > 0) {
                //[0, 1, 2, ... , row-1]-->sum=row
                for (int i = 0; i < row; ++i) {
                    //result[row][i] = 4 * (i + 1)*n - 4 * (i + 1) * (i + 1) - row + i + 1;
                    result[row][i] = 4 * i * n + 4 * n - 4 * i*i - 7 * i - row - 3;
                }
                //[row, row+1, ... , n-row-1]-->sum=n-2*row
                for (int i = row; i < n - row; ++i) {
                    result[row][i] = 4 * row * n - 4 * row * row + i - row + 1;
                }
                //[n-row, n-row+1, ... n-1]-->sum=row
                for (int i = n - row; i < n; ++i) {
                    int j = n - 1 - i;
                    result[row][i] = n + 4 * j * n - 4 * j * j - 3 * j + row;
                }
            }
            else {
                //n-row-1 ... 2row-n+2 ... n-row-1
                //[0,1,2,..., n-row-2] --> sum=n-row-1
                for (int i = 0; i < n - row - 1; ++i) {
                    //result[row][i] = 4 * (i + 1) * n - 4 * (i + 1)*(i + 1) - row + i + 1;
                    result[row][i] = 4 * i * n + 4 * n - 4 * i * i - 7 * i - row - 3;
                }
                //[n-row-1, n-row, n-row+1, ... , row] --> sum=2*row-n+2
                for (int i = n - row - 1; i < row + 1; ++i) {
                    int j = n - 1 - row;
                    //result[row][i] = 4 * j*n + 2 * n - (4 * j*j + 4 * j + 2) + row - i + 1;
                    result[row][i] = 4 * j * n + 3 * n - 4 * j * j - 5 * j - i - 2;
                }
                //[row + 1, row + 2, ... n-1] --> sum=n-row-1
                for (int i = row + 1; i < n; ++i) {
                    int j = n - 1 - i;
                    result[row][i] = 4 * j*n - 4 * j*j + n - 3 * j + row;
                }
            }
        }
        return result;
    }
};

#endif /*_leetcode_algorithm_00059_h_*/
