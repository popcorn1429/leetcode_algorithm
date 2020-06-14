#pragma once
#include "basic_headers.h"

class Solution {
protected:
    class MyIntCompare {
    public:
        bool operator()(const string &a, const string &b) {
            string ab = a + b;
            string ba = b + a;
            return ba < ab;
        }
    };

public:
    string largestNumber(vector<int>& nums) {
        vector<string> strnums;
        convert2str(nums, strnums);

        sort(strnums.begin(), strnums.end(), MyIntCompare());

        string result;
        combine(strnums, result);
        return result;
    }

    void convert2str(const vector<int> &nums, vector<string> &strnums) {
        strnums.reserve(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            strnums.push_back(to_string(nums[i]));
        }
    }

    void combine(const vector<string> &strnums, string &result) {
        for (int i = 0; i < strnums.size(); ++i) {
            result += strnums[i];
        }
        if (result[0] == '0') result.resize(1);
    }
};