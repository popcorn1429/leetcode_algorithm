#ifndef __leetcode_algorithm_00037_h__
#define __leetcode_algorithm_00037_h__
#include <vector>
#include <set>
#include <iostream>
using namespace std;
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<set<char>>> sudoku(9);
        initialize(board, sudoku);

        int ret = try_to_solve(board, sudoku);
        if (ret == -1)
            return;

        if (ret == 0) {
            if (!last_rule(board, sudoku))
                return;
        }
    }

private:

    void initialize(vector<vector<char>>& board, vector<vector<set<char>>>& sudoku) {
        //
        for (int row = 0; row < 9; ++row) {
            sudoku[row].resize(9);
        }

        //
        for (int row = 0; row < 9; ++row) {
            for (int col = 0; col < 9; ++col) {
                if (board[row][col] != '.') {
                    sudoku[row][col].insert(board[row][col]);
                }
                else {
                    for (char c = '1'; c <= '9'; ++c) {
                        sudoku[row][col].insert(c);
                    }
                }
            }
        }
    }

    //使用可靠的规则对现在的局面进行处理
    //如果最后全部求解，则返回1
    //如果存在矛盾（入参不合法，得不到结果），返回-1
    //如果无矛盾，但是靠现有的规则集解决不了问题，依然有空格，则返回0
    int try_to_solve(vector<vector<char>>& board, vector<vector<set<char>>>& sudoku) {
        bool changed = false;
        do {
            changed = false;

            int ret = 0;
            while ((ret = solve_by_rule_1(sudoku)) > 0) { changed = true; }
            if (ret == -1)
                return -1;
            
            if (update_sudoku(board, sudoku))
                changed = true;

            ret = 0;
            while ((ret = solve_by_rule_2(sudoku)) > 0) { changed = true; }
            if (ret == -1)
                return -1;

            if (update_sudoku(board, sudoku))
                changed = true;

        } while (changed);

        bool complete = true;
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    complete = false;
                    break;
                }
            }
            if (!complete)
                break;
        }

        return complete ? 1 : 0;
    }

    bool check_conflits(vector<vector<char>>& board, vector<vector<set<char>>>& sudoku) {

    }


private:
    //当一个空格子的备选值集合仅剩一个元素时，则这个格子就能确定填写这个值了。
    bool update_sudoku(vector<vector<char>>& board, vector<vector<set<char>>>& sudoku) {
        bool updated = false;
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.' && sudoku[i][j].size() == 1) {
                    board[i][j] = *(sudoku[i][j].begin());
                    updated = true;
                }
            }
        }
        return updated;
    }


    //基本规则：同行/同列/同九宫区（以后简称同组），某个格子存在确定值 c，其他空格子的备选值集合中就要排除 c
    //异常 -1
    //没有任何修改 0
    //存在修改 1
    int solve_by_rule_1(vector<vector<set<char>>>& sudoku) {
        bool removed = false;
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (sudoku[i][j].size() == 1) {
                    int ret = remove_potential_digits(sudoku, i, j);
                    if (ret == -1)
                        return -1;
                    else if (ret == 1)
                        removed = true;
                }
            }
        }
        return removed ? 1 : 0;
    }

    //如果同组的所有空格子中，只有一个空格子含有备选值c，那么这个空格子必须填c
    //异常    -1
    //无修改  0
    //有更新   1
    int solve_by_rule_2(vector<vector<set<char>>>& sudoku) {
        bool verified = false;
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (sudoku[i][j].size() > 1) {
                    for (char digit : sudoku[i][j]) {
                        int ret = unique_potential_digit(sudoku, i, j, digit);
                        if (ret == -1)
                            return -1;

                        if (ret == 1) {
                            sudoku[i][j].clear();
                            sudoku[i][j].insert(digit);
                            if (-1 == remove_potential_digits(sudoku, i, j))
                                return -1;
                            
                            verified = true;
                            break;
                        }
                    }
                }
            }
        }
        return verified ? 1 : 0;
    }

private:
    //异常 -1
    //没有任何修改 0
    //存在修改 1
    int remove_potential_digits(vector<vector<set<char>>>& sudoku, int row, int col) {
        char c = *(sudoku[row][col].begin());
        //same row
        bool modified = false;
        for (int i = 0; i < 9; ++i) {
            if (i == col)
                continue;

            set<char> &digits = sudoku[row][i];
            if (digits.find(c) != digits.end()) {
                if (digits.size() == 1)
                    return -1;

                digits.erase(c);
                if (!modified)
                    modified = true;
            }
        }

        //same col
        for (int i = 0; i < 9; ++i) {
            if (i == row)
                continue;

            set<char> &digits = sudoku[i][col];
            if (digits.find(c) != digits.end()) {
                if (digits.size() == 1)
                    return -1;

                digits.erase(c);
                if (!modified)
                    modified = true;
            }
        }

        //same little_board
        int begin_row = (row / 3) * 3;
        int begin_col = (col / 3) * 3;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (begin_row + i == row && begin_col + j == col)
                    continue;

                set<char>& digits = sudoku[begin_row + i][begin_col + j];
                if (digits.find(c) != digits.end()) {
                    if (digits.size() == 1)
                        return -1;

                    digits.erase(c);
                    if (!modified)
                        modified = true;
                }
            }
        }

        return modified ? 1 : 0;
    }

    //异常   -1
    //不唯一 0
    //唯一   1
    int unique_potential_digit(vector<vector<set<char>>>& sudoku, int row, int col, char digit) {
        //same row
        bool unique = true;
        for (int i = 0; i < 9; ++i) {
            if (i == col)
                continue;

            if (sudoku[row][i].size() == 1 && sudoku[row][i].find(digit) != sudoku[row][i].end()) {
                return -1;
            }

            if (sudoku[row][i].size() > 1 && sudoku[row][i].find(digit) != sudoku[row][i].end()) {
                unique = false;
                break;
            }
        }
        if (unique)
            return 1;
        

        //same col
        unique = true;
        for (int i = 0; i < 9; ++i) {
            if (i == row)
                continue;

            if (sudoku[i][col].size() == 1 && sudoku[i][col].find(digit) != sudoku[i][col].end()) {
                return -1;
            }

            if (sudoku[i][col].size() > 1 && sudoku[i][col].find(digit) != sudoku[i][col].end()) {
                unique = false;
                break;
            }
        }
        if (unique)
            return 1;


        //same little_board
        unique = true;
        int begin_row = (row / 3) * 3;
        int begin_col = (col / 3) * 3;
        for (int i = begin_row; i < begin_row + 3; ++i) {
            for (int j = begin_col; j < begin_col + 3; ++j) {
                if (i == row && j == col)
                    continue;

                if (sudoku[i][j].size() == 1 && sudoku[i][j].find(digit) != sudoku[i][j].end()) {
                    return -1;
                }

                if (sudoku[i][j].size() > 1 && sudoku[i][j].find(digit) != sudoku[i][j].end()) {
                    unique = false;
                    break;
                }
            }
            if (!unique)
                break;
        }
        
        return unique ? 1 : 0;
    }

    
    //之前的规则各种尝试之后还是没有完全解决？
    //试试这个，猜数字大法，从空格子的备选数中选择一个当做解，然后再次利用前面的规则解题，如果没有出现矛盾且解答，则认为成功求解。
    //如果没有矛盾，但是还是没有全部解出，继续从剩下的空格子中找一个，再猜。重复这个过程。
    //如果出现矛盾，回退最近的猜的数字，换一个备选的数再猜。
    //如果所有备选都猜了一遍，还是矛盾。那就退到更早的一个空格子，重新猜。
    //说白了，一个递归的过程。
    bool last_rule(vector<vector<char>>& board, vector<vector<set<char>>>& sudoku) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (sudoku[i][j].size() > 1) {
                    for (char digit : sudoku[i][j]) {
                        vector<vector<char>> dup_board(board);
                        vector<vector<set<char>>> dup_sudoku(sudoku);
                        dup_board[i][j] = digit;
                        dup_sudoku[i][j].clear();
                        dup_sudoku[i][j].insert(digit);
                        if (guess_digit(dup_board, dup_sudoku, i, j, digit)) {
                            board = dup_board;
                            sudoku = dup_sudoku;
                            return true;
                        }
                    }
                }
            }
        }

        return false;
    }

    int guess_digit(vector<vector<char>>& board, vector<vector<set<char>>>& sudoku, int row, int col, char digit) {
        int ret = try_to_solve(board, sudoku);
        if (-1 == ret)
            return false;
        
        if (ret == 1)
            return true;

        return last_rule(board, sudoku);
    }
};
#endif
