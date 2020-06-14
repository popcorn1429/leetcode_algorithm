#pragma once
#include "basic_headers.h"

class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        sums.swap(matrix);
        for (int row = 0; row < sums.size(); ++row) {
            for (int col = 0; col < sums[0].size(); ++col) {
                if (row == 0) {
                    if (col == 0) continue;
                    else {
                        sums[row][col] = sums[row][col - 1] + sums[row][col];
                    }
                }
                else {
                    if (col == 0) {
                        sums[row][col] = sums[row - 1][col] + sums[row][col];
                    }
                    else {
                        sums[row][col] = sums[row - 1][col] + sums[row][col - 1] - sums[row - 1][col - 1] + sums[row][col];
                    }
                }
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        if (row1 == 0) {
            if (col1 == 0) return sums[row2][col2];
            else return sums[row2][col2] - sums[row2][col1 - 1];
        }
        else {
            if (col1 == 0) return sums[row2][col2] - sums[row1 - 1][col2];
            else return sums[row2][col2] - sums[row2][col1 - 1] - sums[row1 - 1][col2] + sums[row1 - 1][col1 - 1];
        }
    }

private:
    vector<vector<int>> sums;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */