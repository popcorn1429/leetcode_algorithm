#ifndef __leetcode_algorithm_36_h__
#define __leetcode_algorithm_36_h__
#include <vector>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int col = 0; col < 9; ++col) {
            for (int row = 0; row < 9; ++row) {
                if (!isValidChar(board, col, row))
                    return false;
            }
        }
        return true;
    }

    bool isValidChar(const vector<vector<char>>& board, int col, int row) {
        char c = board[col][row];
        
        if ('.' == c)
            return true;

        //row
        for (int i = 0; i < 9; ++i) {
            if (c == board[i][row] && i != col)
                return false;
        }

        //col
        for (int j = 0; j < 9; ++j) {
            if (c == board[col][j] && j != row)
                return false;
        }

        //little-board
        int little_row = (row / 3) * 3;
        int little_col = (col / 3) * 3;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (c == board[little_col + i][little_row + j] && !(little_col + i == col && little_row + j == row))
                    return false;
            }
        }

        return true;
    }
};
#endif