#ifndef __leetcode_algorithm_37_2_h__
#define __leetcode_algorithm_37_2_h__

#include <vector>
#include <set>
#include <iostream>
using namespace std;
class Solution_2 {
public:
    void solveSudoku(vector<vector<char>>& board) {
        if (solve(board))
            return;
    }

    bool solve(vector<vector<char>>& board) {
        int guess_col = -1;
        int guess_row = -1;
        for (int col = 0; col < 9; ++col) {
            for (int row = 0; row < 9; ++row) {
                if (board[col][row] == '.') {
                    guess_col = col;
                    guess_row = row;
                    break;
                }
            }
            if (-1 != guess_col)
                break;
        }

        if (guess_col == -1) {
            return true;
        }

        for (char c = '1'; c <= '9'; ++c) {
            board[guess_col][guess_row] = c;
            if (isValidChar(board, guess_col, guess_row)) {
                if (solve(board)) return true;
            }
        }
        board[guess_col][guess_row] = '.';
        return false;
    }

    bool complete_sudoku(vector<vector<char>>& board) {
        bool complete = true;
        for (int col = 0; col < 9; ++col) {
            for (int row = 0; row < 9; ++row) {
                if (board[col][row] == '.')
                    complete = false;
            }
        }
        return complete;
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