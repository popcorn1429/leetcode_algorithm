#pragma once
#include "basic_headers.h"

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for (int i = 0; i < numbers.size(); ++i) {
            if (numbers[i] * 2 > target) break;
            int v = target - numbers[i];

            int pos = find(numbers, i, numbers.size(), v);
            if (pos != -1 && pos != i) return { i + 1, pos + 1 };
        }
        return {};
    }

    int find(const vector<int> &numbers, int left, int right, int target) {
        if (left == right) return -1;
        if (left + 1 == right) return numbers[left] == target ? left : -1;

        int middle = (left + right) / 2;
        while (left + 1 < right) {
            if (numbers[middle] == target) return middle;
            if (numbers[middle] < target) left = middle;
            else right = middle;
            middle = (left + right) / 2;
        }

        if (left + 1 == right) return numbers[left] == target ? left : -1;
        return middle;
    }
};