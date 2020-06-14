#ifndef __leetcode_algorithm_00050_h__
#define __leetcode_algorithm_00050_h__

class Solution {
public:
    double myPow(double x, int n) {
        long ln = n;
        if (x > -0.0000001 && x < 0.0000001)
            return 0;
        
        if (ln == 0)
            return 1;
        else if (ln < 0) {
            x = 1 / x;
            ln = -ln;
        }
            

        double tmp[128];
        tmp[0] = 1;
        tmp[1] = x;

        int i = 1;
        while (true) {
            unsigned long t = 1L << i;
            if (t <= ln) {
                tmp[i + 1] = tmp[i] * tmp[i];
                ++i;
            }
            else {
                break;
            }
        }
        
        double result = 1;
        for (int j = 0; j < i; ++j) {
            if (((ln >> j) & 1) == 1)
                result *= tmp[j + 1];
        }

        return result;
    }
};
#endif
