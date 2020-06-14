#pragma once
#include "basic_headers.h"

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        if (dungeon.empty()) return 0;

        vector<vector<int>> routes(dungeon);

        int rowcnt = dungeon.size();
        int colcnt = dungeon[0].size();

        routes[rowcnt - 1][colcnt - 1] = (1 - dungeon[rowcnt - 1][colcnt - 1] < 1) ? 1 : (1 - dungeon[rowcnt - 1][colcnt - 1]);

        for (int i = 1; i < rowcnt + colcnt; ++i) {
            for (int j = 0; j <= i; ++j) {
                update(dungeon, routes, rowcnt - 1 - j, colcnt - 1 - (i - j));
            }
        }

        return routes[0][0];
    }

    void update(vector<vector<int>> &dungeon, vector<vector<int>> &routes, int row, int col) {
        int rowcnt = dungeon.size();
        int colcnt = dungeon[0].size();

        if (row < 0 || row >= rowcnt) return;
        if (col < 0 || col >= colcnt) return;

        //down
        int val = -1;
        if (row + 1 < rowcnt) {
            int v = routes[row + 1][col] - dungeon[row][col];;
            val = (v < 1) ? 1 : v;
        }

        //right
        if (col + 1 < colcnt) {
            int v = routes[row][col + 1] - dungeon[row][col];
            int _v = (v < 1) ? 1 : v;
            if (val < 0) val = _v;
            else {
                val = _v < val ? _v : val;
            }
        }

        routes[row][col] = val;
    }
};