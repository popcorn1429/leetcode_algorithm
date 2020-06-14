/*
Spiral Matrix
    Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

Example:
  Input:
  [
    [ 1, 2, 3 ],
    [ 4, 5, 6 ],
    [ 7, 8, 9 ]
  ]
  Output: [1,2,3,6,9,8,7,4,5]
*/

#ifndef _leetcode_algorithm_00054_h_
#define _leetcode_algorithm_00054_h_
#include "basic_headers.h"

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty())
            return vector<int>();

        if (matrix.front().empty())
            return vector<int>();

        vector<int> result;
        result.reserve(matrix.size() * matrix.front().size());

        spiral(matrix, 0, 0, matrix.size(), matrix.front().size(), result);
        return result;
    }

    void spiral(const vector<vector<int>>& matrix, int cur_row, int cur_col, int row_cnt, int col_cnt, vector<int>& result) {
        //end-condition 1:
        if (row_cnt <= 0 || col_cnt <= 0)
            return;
        
        //end-condition 2:
        if (row_cnt == 1) {
            for (auto i = cur_col; i < cur_col + col_cnt; ++i) {
                result.push_back(matrix[cur_row][i]);
            }
            return;
        }

        //end-condition 3:
        if (col_cnt == 1) {
            for (auto i = cur_row; i < cur_row + row_cnt; ++i) {
                result.push_back(matrix[i][cur_col]);
            }
            return;
        }
        
        //left->right
        for (auto i = cur_col; i < cur_col + col_cnt; ++i) {
            result.push_back(matrix[cur_row][i]);
        }
        //up -> down
        for (auto i = cur_row + 1; i < row_cnt + cur_row; ++i) {
            result.push_back(matrix[i][cur_col + col_cnt - 1]);
        }
        //right->left
        for (auto i = cur_col + col_cnt - 1 - 1; i >= cur_col; --i) {
            result.push_back(matrix[cur_row + row_cnt - 1][i]);
        }
        //down -> up
        for (auto i = cur_row + row_cnt - 1 - 1; i > cur_row; --i) {
            result.push_back(matrix[i][cur_col]);
        }
        //spiral~
        spiral(matrix, cur_row + 1, cur_col + 1, row_cnt - 2, col_cnt - 2, result);
    }
};

#endif /*_leetcode_algorithm_00054_h_*/
