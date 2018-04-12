#ifndef _leetcode_algorithm_7_h_
#define 
#include <iostream>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        long long s = 0;
        int abx = x < 0 ? -x : x;

        while (abx > 0) {
            int t = abx % 10;
            s = s * 10 + t;
            abx /= 10;
        }

        s = x < 0 ? -s : s;

        int ss = (int)s;

        if (ss != s)
            return 0;
        else
            return ss;
    }
};

#endif /*_leetcode_algorithm_7_h_*/