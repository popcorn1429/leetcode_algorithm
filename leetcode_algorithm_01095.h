#pragma once
#include "basic_headers.h"

class MountainArray {
public:
    int get(int index);
    int length();
};

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int peekIndex = findPeek(mountainArr);
        int leftmost = mountainArr.get(0);
        int peek = mountainArr.get(peekIndex);
        int rightmost = mountainArr.get(mountainArr.length() - 1);

        int pos = findTarget(target, mountainArr, 0, peekIndex + 1, true);
        if (-1 != pos) return pos;
        return findTarget(target, mountainArr, peekIndex, mountainArr.length(), false);
    }

    int findPeek(MountainArray &mountainArr) {
        int start = 0;
        int end = mountainArr.length();
        while (end - start > 1) {
            int middle = (start + end - 1) / 2;
            if (mountainArr.get(middle + 1) - mountainArr.get(middle) > 0) {
                start = middle + 1;
            }
            else end = middle + 1;
        }
        return start;
    }

    int findTarget(int target, MountainArray &mountainArr, int start, int end, bool ascendent) {
        while (end - start > 1) {
            int middle = (start + end - 1) / 2;
            int middleValue = mountainArr.get(middle);

            if (middleValue == target) return middle;

            if ((middleValue < target && ascendent)
                || (target < middleValue && !ascendent)) start = middle + 1;
            else end = middle;
        }
        if (mountainArr.get(start) == target) return start;
        return -1;
    }
};