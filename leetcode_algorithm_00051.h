/*
N-Queens
    The n-queens puzzle is the problem of placing n queens on an n¡Án chessboard such that no two queens attack each other.
    Given an integer n, return all distinct solutions to the n-queens puzzle.

    Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.
*/

#ifndef __leetcode_algorithm_00051_52_h__
#define __leetcode_algorithm_00051_52_h__
#include "basic_headers.h"

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<int> solution;
        solution.reserve(n);
        vector<vector<int>> solutions;

        NQueens(n, solution, solutions);


        vector<vector<string>> result;
        translate(n, solutions, result);
        return result;
    }

private:

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

    void updateRow(string& strRow, int pos) {
        for (string::size_type i = 0; i < strRow.size(); ++i) {
            strRow[i] = (pos == i) ? 'Q' : '.';
        }
    }

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

#endif /*__leetcode_algorithm_00051_52_h__*/
