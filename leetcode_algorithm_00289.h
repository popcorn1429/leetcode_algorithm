#pragma once
#include "basic_headers.h"

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int dir_col[] = { -1,  0,  1, -1, 1, -1, 0, 1 };
        int dir_row[] = { -1, -1, -1,  0, 0,  1, 1, 1 };

        for (int r = 0; r < board.size(); ++r) {
            vector<int> &row = board[r];
            for (int c = 0; c < row.size(); ++c) {
                int around = 0;
                for (int idx = 0; idx < sizeof(dir_col) / sizeof(int); ++idx) {
                    if (r + dir_row[idx] >= 0 && r + dir_row[idx] < board.size() && c + dir_col[idx] >= 0 && c + dir_col[idx] < row.size()) {
                        around += (board[r + dir_row[idx]][c + dir_col[idx]] & 1);
                    }
                }

                if (row[c] & 1 == 1) {
                    if (around == 2 || around == 3) row[c] |= 2;
                }
                else {
                    if (around == 3) row[c] |= 2;
                }
            }
        }

        for (int r = 0; r < board.size(); ++r) {
            vector<int> &row = board[r];
            for (int c = 0; c < row.size(); ++c) {
                row[c] >>= 1;
            }
        }
    }
};