#ifndef __leetcode_algorithm_00264_h__
#define __leetcode_algorithm_00264_h__
#include "basic_headers.h"

using namespace std;

class Solution {
public:
    int nthUglyNumber(int n)
    {
        if (1 == n)
            return 1;

        vector<int> ugly{1};
        vector<int>::size_type idx2 = 0;
        vector<int>::size_type idx3 = 0;
        vector<int>::size_type idx5 = 0;

        for (int i = 0; i < n-1; ++i)
        {
            int num2 = ugly[idx2] * 2;
            int num3 = ugly[idx3] * 3;
            int num5 = ugly[idx5] * 5;
            int num = min(min(num2, num3), num5);
            ugly.push_back(num);
            if (num == num2)
                ++idx2;
            else if (num == num3)
                ++idx3;
            else
                ++idx5;
        }
        return ugly.back();
    }

    //稍微慢一些，但也满足了要求
    int nthUglyNumber__(int n)
    {
        set<int> numbers;
        numbers.insert(1);
        int number = 0;
        for (int i = 0; i < n; ++i)
        {
            number = *numbers.begin();
            numbers.erase(numbers.begin());
            if (number * 2 < INT32_MAX) numbers.insert(number * 2);
            if (number * 3 < INT32_MAX) numbers.insert(number * 3);
            if (number * 5 < INT32_MAX) numbers.insert(number * 5);
        }
        return number;
    }
};
#endif
