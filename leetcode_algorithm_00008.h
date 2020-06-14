#pragma once
#include "basic_headers.h"

class Solution {
public:
    int myAtoi(string str) {
        if (str.empty())
            return 0;

        long number = 0;
        const char* src = str.c_str();
        const char* p = src;
        while (*p == ' ' || *p == '\t' || *p == '\n')
        {
            ++p;
        }

        char first = *p;
        if (first == '+' || first == '-') {
            long v = simple_get_decimal(p + 1);
            if ('+' == first && v > INT_MAX)
                return INT_MAX;
            else if ('-' == first)
                return -v;
            return v;
        }
        else if (first >= '0' && first <= '9') {
            long v = simple_get_decimal(p);
            if (v > INT_MAX)
                return INT_MAX;
            else
                return v;
        }
        else {
            return 0;
        }
    }

    long simple_get_decimal(const char* src) {
        long number = 0;
        const char* p = src;
        while (*p >= '0' && *p <= '9') {
            number *= 10;
            number += *p - '0';
            if (number > long(INT_MAX) + 1)
                return INT_MAX + 1l;

            ++p;
        }
        return number;
    }
};