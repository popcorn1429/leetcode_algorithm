#pragma once
#include "basic_headers.h"

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int count = nums1.size() + nums2.size();
        int middle_left = count / 2;
        int middle_right = middle_left;
        if (count % 2 == 0)
            ++middle_right;
        else {
            ++middle_left;
            middle_right = middle_left;
        }

        int pos1 = 0;
        int pos2 = 0;
        int curNum = 0;
        int cur1 = 0;
        int cur2 = 0;
        int left = 0;
        int right = 0;

        while (pos1 + pos2 <= middle_right) {

            if (pos1 < nums1.size())
                cur1 = nums1[pos1];
            else
                cur1 = INT_MAX;

            if (pos2 < nums2.size())
                cur2 = nums2[pos2];
            else
                cur2 = INT_MAX;

            if (cur1 < cur2) {
                curNum = cur1;
                ++pos1;
            }
            else {
                curNum = cur2;
                ++pos2;
            }

            if (pos1 + pos2 == middle_left)
                left = curNum;

            if (pos1 + pos2 == middle_right) {
                right = curNum;
                break;
            }
        }
        return (left + right) / 2.0;
    }
};