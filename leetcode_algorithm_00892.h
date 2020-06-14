#ifndef __leetcode_algorithm_00892_h__
#define __leetcode_algorithm_00892_h__

#include "basic_headers.h"

class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int surface = 0;
        for (size_t iRow = 0; iRow < grid.size(); ++iRow) {
            for (size_t iCol = 0; iCol < grid[iRow].size(); ++iCol) {
                int curTile = grid[iRow][iCol];
                if (curTile != 0) {
                    surface += 2;  //top(1) and bottom(1)
                    
                    //in & out & left & right
                    surface += (4* curTile);

                    if (iCol > 0)
                        surface -= min(grid[iRow][iCol - 1], curTile);

                    if (iCol < grid[iRow].size() - 1)
                        surface -= min(grid[iRow][iCol + 1], curTile);

                    if (iRow > 0)
                        surface -= min(grid[iRow - 1][iCol], curTile);
                    
                    if (iRow < grid.size() - 1)
                        surface -= min(grid[iRow + 1][iCol], curTile);
                }
            }
        }
        return surface;
    }
};

#endif /*__leetcode_algorithm_00892_h__*/
