#pragma once
#include "basic_headers.h"

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> intersected;
        int n = nums2.size();
        for (int i = 0; i < nums1.size(); ++i) {
            int pos = getpos(nums2, 0, n, nums1[i]);
            if (pos != n) {
                nums2[pos] = nums2[n - 1];
                --n;
                intersected.push_back(nums1[i]);
            }
        }
        return intersected;
    }

    int getpos(const vector<int>& nums2, int from, int to, int val) {
        for (int i = from; i < to; ++i) {
            if (val == nums2[i])
                return i;
        }
        return to;
    }
};