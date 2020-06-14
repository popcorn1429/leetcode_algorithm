#pragma once
#include "basic_headers.h"

class Solution {
public:
    int totalNQueens(int n) {
        vector<int> solution;
        solution.reserve(n);

        int total = 0;
        NQueens(n, solution, total);
        return total;
    }

private:
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