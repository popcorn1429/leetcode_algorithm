#pragma once
#include "basic_headers.h"

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        quick_sort(nums, 0, nums.size());
        return max(nums[0] * nums[1] * nums[nums.size() - 1], nums[nums.size() - 1] * nums[nums.size() - 2] * nums[nums.size() - 3]);
    }

    void quick_sort(vector<int> &elements, size_t start, size_t end) {
        size_t sz = end - start;
        if (sz < 2) return;

        const int &flag = elements[start];
        size_t left = start + 1;
        size_t right = end - 1;
        while (left < right) {
            while (left < right && elements[left] <= flag) ++left;
            while (left < right && flag < elements[right]) --right;

            if (left < right) {
                swap(elements[left], elements[right]);
            }
        }
        if (elements[left] <= flag) {
            swap(elements[start], elements[left]);
            quick_sort(elements, start, left);
            quick_sort(elements, left + 1, end);
        }
        else {
            swap(elements[start], elements[left - 1]);
            quick_sort(elements, start, left - 1);
            quick_sort(elements, left, end);
        }
    }
};