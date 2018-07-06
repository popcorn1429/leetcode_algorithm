#pragma once
#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int max_pos = findMaxRight(height, -1);
        
        int sum = 0;
        sum += right_sum(height, max_pos);
        sum += left_sum(height, max_pos);
        return sum;
    }

    int right_sum(const vector<int>& height, int begin_pos) {
        int max_pos = findMaxRight(height, begin_pos);
        if (max_pos == begin_pos) {
            return 0;
        }
        else {
            int sum = 0;
            int max = height[max_pos];
            for (int pos = begin_pos + 1; pos != max_pos; ++pos) {
                sum += (max - height[pos]);
            }

            sum += right_sum(height, max_pos);
            return sum;
        }
    }

    int left_sum(const vector<int>& height, int begin_pos) {
        int max_pos = findMaxLeft(height, begin_pos);
        if (max_pos == begin_pos) {
            return 0;
        }
        else {
            int sum = 0;
            int max = height[max_pos];
            for (int pos = begin_pos - 1; pos != max_pos; --pos) {
                sum += (max - height[pos]);
            }

            sum += left_sum(height, max_pos);
            return sum;
        }
    }

    int findMaxRight(const vector<int>& height, int begin_pos) {
        int max_height = 0;
        int max_pos = begin_pos;

        int sz = height.size();
        for (int pos = begin_pos+1; pos < sz; ++pos) {
            if (height[pos] >= max_height) {
                max_pos = pos;
                max_height = height[pos];
            }
        }
        
        return max_pos;
    }

    int findMaxLeft(const vector<int>& height, int begin_pos) {
        int max_height = 0;
        int max_pos = begin_pos;

        int sz = height.size();
        for (int pos = begin_pos - 1; pos >= 0; --pos) {
            if (height[pos] >= max_height) {
                max_pos = pos;
                max_height = height[pos];
            }
        }

        return max_pos;
    }
};