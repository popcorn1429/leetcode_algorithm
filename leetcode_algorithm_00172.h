#pragma once
#include "basic_headers.h"

class Solution {
public:
    int trailingZeroes(int n) {
        int count2 = 0;
        int count5 = 0;

        long factor2 = 2;
        long factor5 = 5;

        while (factor2 <= n) {
            count2 += (n / factor2);
            factor2 *= 2;
        }
        while (factor5 <= n) {
            count5 += (n / factor5);
            factor5 *= 5;
        }

        return (count5 < count2) ? count5 : count2;
    }
};