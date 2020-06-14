#ifndef __leetcode_algorithm_00073_h__
#define __leetcode_algorithm_00073_h__
#include "basic_headers.h"

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.empty())
            return;
        if (matrix[0].empty())
            return;

        bool first_row_need_set_to_zero = false;
        for (int i : matrix[0]) {
            if (i == 0) {
                first_row_need_set_to_zero = true;
                break;
            }
        }

        int row_cnt = matrix.size();
        int col_cnt = matrix[0].size();
        for (int col = 0; col != col_cnt; ++col) {
            for (int row = 0; row != row_cnt; ++row) {
                if (matrix[row][col] == 0) {
                    matrix[0][col] = 0;
                    if (row != 0) {
                        matrix[row][0] = 0;
                    }
                }
            }
        }

        for (int row = 1; row != row_cnt; ++row) {
            if (matrix[row][0] == 0) {
                for (int col = 1; col != col_cnt; ++col) {
                    matrix[row][col] = 0;
                }
            }
        }

        for (int col = 0; col != col_cnt; ++col) {
            if (matrix[0][col] == 0) {
                for (int row = 1; row != row_cnt; ++row) {
                    matrix[row][col] = 0;
                }
            }
        }

        if (first_row_need_set_to_zero) {
            for (int col = 0; col != col_cnt; ++col) {
                matrix[0][col] = 0;
            }
        }
    }

    void printMatrix(const vector<vector<int>>& matrix) {
        for (int row = 0; row != matrix.size(); ++row) {
            for (int col = 0; col != matrix[0].size(); ++col) {
                cout << setw(4) << matrix[row][col] << "  ";
            }
            cout << '\n';
        }
        cout << endl;
    }
};

#endif /*__leetcode_algorithm_00073_h__*/
