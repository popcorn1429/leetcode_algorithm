#ifndef __LEETCODE_ALGORITHM_13_H__
#define __LEETCODE_ALGORITHM_13_H__
#include <string>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        const char* p = s.c_str();
        while (*p != '\0') {
            int cur = romanValue(*p);
            int next = romanValue(*(p + 1));
            //if ((cur * 10 != next) && (cur*5 != next)) {
            if (cur >= next) {
                result += cur;
            }
            else {
                result -= cur;
            }
            ++p;
        }
        return result;
    }

    int romanValue(char c) {
        switch (c)
        {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            break;
        }
        return 0;
    }
};


#endif