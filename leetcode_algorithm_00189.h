#pragma once
#include "basic_headers.h"
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        if (k == 0) return;
        int replaced = 0;
        int initial = 0;
        int current = initial;
        int next = (current + k) % nums.size();

        int temp = nums[current];
        while (replaced < nums.size()) {
            swap(temp, nums[next]);
            ++replaced;

            current = next;
            if (current == initial && initial < k) {
                ++initial;
                current = initial;
                temp = nums[current];
            }

            next = (current + k) % nums.size();
        }
    }

    //////////////////////////
    void rotate2(vector<int>& nums, int k) {
        k = k % nums.size();

        reverse(nums, 0, nums.size());
        reverse(nums, 0, k);
        reverse(nums, k, nums.size());
    }

    void reverse(vector<int> &nums, size_t start, size_t end) {
        int n = end - start;
        for (int i = 0; i < n / 2; ++i) {
            swap(nums[start + i], nums[end - 1 - i]);
        }
    }
};