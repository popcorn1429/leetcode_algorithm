/*
N-Queens
    The n-queens puzzle is the problem of placing n queens on an n��n chessboard such that no two queens attack each other.
    Given an integer n, return all distinct solutions to the n-queens puzzle.

    Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.
*/

#ifndef _leetcode_algorithm_51_52_h_
#define _leetcode_algorithm_51_52_h_
#include "basic_headers.h"
class Solution {
public:
    //question 51
    vector<vector<string>> solveNQueens(int n) {
        vector<int> solution;
        solution.reserve(n);
        vector<vector<int>> solutions;

        NQueens(n, solution, solutions);


        vector<vector<string>> result;
        translate(n, solutions, result);
        return result;
    }

    //question 52
    int totalNQueens(int n) {
        vector<int> solution;
        solution.reserve(n);

        int total = 0;
        NQueens(n, solution, total);
        return total;
    }

private:
    //for 51
    void NQueens(int n, vector<int>& solution, vector<vector<int>>& solutions) {
        if (solution.size() == n) {
            solutions.push_back(solution);
            return;
        }

        for (int i = 0; i < n; ++i) {
            if (check(solution, i)) {
                solution.push_back(i);
                NQueens(n, solution, solutions);
                solution.pop_back();
            }
        }
    }
    //for 51
    void translate(int n, const vector<vector<int>>& solutions, vector<vector<string>>& result) {
        string strRow(n, '.');
        for (const auto& solution : solutions) {
            result.push_back(vector<string>());
            result.back().reserve(n);
            for (int pos : solution) {
                updateRow(strRow, pos);
                result.back().push_back(strRow);
            }
        }
    }
    //for 51
    void updateRow(string& strRow, int pos) {
        for (string::size_type i = 0; i < strRow.size(); ++i) {
            strRow[i] = (pos == i) ? 'Q' : '.';
        }
    }

private:
    //for 52
    void NQueens(int n, vector<int>& solution, int& total) {
        if (solution.size() == n) {
            ++total;
            return;
        }

        for (int i = 0; i < n; ++i) {
            if (check(solution, i)) {
                solution.push_back(i);
                NQueens(n, solution, total);
                solution.pop_back();
            }
        }
    }

private:
    //tool-func for question 51 & 52
    bool check(const vector<int>& solution, int i) {
        auto sz = solution.size();
        bool bOK = true;

        for (decltype(sz) n = 0; n < sz; ++n) {
            if (i == solution[n] || i == solution[n] + sz - n || i == solution[n] - sz + n) {
                bOK = false;
                break;
            }
        }

        return bOK;
    }
};


#endif /*_leetcode_algorithm_51_52_h_*/