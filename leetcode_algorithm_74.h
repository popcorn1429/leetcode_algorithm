#ifndef __leetcode_algorithm_74_h__
#define __leetcode_algorithm_74_h__

#include "basic_headers.h"
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty())
            return false;

        size_t row = matrix.size();
        size_t col = matrix[0].size();
        size_t cnt = row * col;
        //b-search
        size_t start_pos = 0;
        size_t end_pos = cnt;
        while (start_pos < end_pos) {
            size_t mid_pos = (start_pos + end_pos) / 2;
            size_t mid_row = mid_pos / col;
            size_t mid_col = mid_pos % col;
            if (matrix[mid_row][mid_col] == target)
                return true;
            else if (matrix[mid_row][mid_col] < target)
                start_pos = mid_pos+1;
            else
                end_pos = mid_pos;
        }
        return false;
    }
};

#endif /*__leetcode_algorithm_74_h__*/
