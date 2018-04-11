#ifndef __leetcode_algorithm_48_h__
#define __leetcode_algorithm_48_h__
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        size_t n = matrix.size();
        if (n % 2 == 0) {
            size_t h = n / 2;
            for (size_t i = 0; i < h; ++i) {
                for (size_t j = 0; j < h; ++j) {
                    rotate(matrix, n, i, j);
                }
            }
        }
        else {
            size_t h = (n + 1) / 2;
            for (size_t i = 0; i < h - 1; ++i) {
                for (size_t j = 0; j < h; ++j) {
                    rotate(matrix, n, i, j);
                }
            }
        }
    }

private:
    void rotate(vector<vector<int>>& matrix, size_t n, size_t i, size_t j) {
        int first = matrix[i][j];
        int second = matrix[j][n-1-i];
        int third = matrix[n-1-i][n-1-j];
        int fourth = matrix[n-1-j][i];

        matrix[i][j] = fourth;
        matrix[j][n - 1 - i] = first;
        matrix[n - 1 - i][n - 1 - j] = second;
        matrix[n - 1 - j][i] = third;
    }
};

#endif