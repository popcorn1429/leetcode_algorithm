#ifndef __leetcode_algorithm_79_h__
#define __leetcode_algorithm_79_h__
#include "basic_headers.h"

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int cnt_row = board.size();
        if (cnt_row == 0)
            return false;
        int cnt_col = board[0].size();
        if (cnt_col == 0)
            return false;

        vector<int> positions;
        return match_char(board, cnt_row, cnt_col, word, 0, positions);
    }

    bool match_char(const vector<vector<char>> &board, int cnt_row, int cnt_col, const string &word, int pos, vector<int> &positions) {
        if (pos == word.size())
            return true;
        else if (pos == 0) {
            //the first character can be anywhere in this board
            for (int row = 0; row != cnt_row; ++row) {
                for (int col = 0; col != cnt_col; ++col) {
                    if (board[row][col] == word[pos]) {
                        positions.push_back(row * cnt_col + col);
                        if (match_char(board, cnt_row, cnt_col, word, pos + 1, positions)) {
                            return true;
                        }
                        positions.pop_back();
                    }
                }
            }
        }
        else {
            //this character must be somewhere adjacent to the previous character.
            int prev_pos = positions.back();
            int prev_pos_row = prev_pos / cnt_col;
            int prev_pos_col = prev_pos % cnt_col;
            //left
            if (prev_pos_col != 0 && board[prev_pos_row][prev_pos_col-1] == word[pos] 
                && find(positions.begin(), positions.end(), prev_pos-1) == positions.end()) {
                //seems good, let's assume this is the correct choice.
                positions.push_back(prev_pos - 1);
                if (match_char(board, cnt_row, cnt_col, word, pos + 1, positions)) {
                    return true;
                }
                //oops, it doesn't work~ rollback~
                positions.pop_back();
            }
            //up
            if (prev_pos_row != 0 && board[prev_pos_row - 1][prev_pos_col] == word[pos]
                && find(positions.begin(), positions.end(), prev_pos - cnt_col) == positions.end()) {
                //seems good, let's assume this is the correct choice.
                positions.push_back(prev_pos - cnt_col);
                if (match_char(board, cnt_row, cnt_col, word, pos + 1, positions)) {
                    return true;
                }
                //oops, it doesn't work~ rollback~
                positions.pop_back();
            }
            //right
            if (prev_pos_col != cnt_col-1 && board[prev_pos_row][prev_pos_col+1] == word[pos]
                && find(positions.begin(), positions.end(), prev_pos + 1) == positions.end()) {
                //seems good, let's assume this is the correct choice.
                positions.push_back(prev_pos + 1);
                if (match_char(board, cnt_row, cnt_col, word, pos + 1, positions)) {
                    return true;
                }
                //oops, it doesn't work~ rollback~
                positions.pop_back();
            }
            //down
            if (prev_pos_row != cnt_row - 1 && board[prev_pos_row+1][prev_pos_col] == word[pos]
                && find(positions.begin(), positions.end(), prev_pos + cnt_col) == positions.end()) {
                //seems good, let's assume this is the correct choice.
                positions.push_back(prev_pos + cnt_col);
                if (match_char(board, cnt_row, cnt_col, word, pos + 1, positions)) {
                    return true;
                }
                //oops, it doesn't work~ rollback~
                positions.pop_back();
            }
        }
        return false;
    }
};

#endif /*__leetcode_algorithm_79_h__*/
