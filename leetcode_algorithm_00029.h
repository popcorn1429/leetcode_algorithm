#ifndef __leetcode_algorithm_00029_h__
#define __leetcode_algorithm_00029_h__
#include <vector>
using namespace std;
class Solution {
public:
    int divide(int dividend, int divisor) {
        //
        if (divisor == 0)
            return INT_MAX;
        else if (dividend == 0)
            return 0;

        unsigned abs_dividend = (dividend < 0) ? -dividend : dividend;
        unsigned abs_divisor = (divisor < 0) ? -divisor : divisor;
        bool positive = (dividend < 0 && divisor < 0) || (0 < dividend && 0 < divisor);
        
        if (abs_dividend < abs_divisor)
            return 0;

        vector<unsigned long long> divisors;
        unsigned long long cur = abs_divisor;
        //divisors.push_back(divisor);
        while (cur <= abs_dividend) {
            divisors.push_back(cur);
            cur <<= 1;
        }

        long long ret = 0;
        while (abs_dividend >= abs_divisor) {
            for (int i = divisors.size() - 1; i >= 0; --i) {
                if (abs_dividend >= divisors[i]) {
                    ret += (1ll << i);
                    abs_dividend -= divisors[i];
                }
            }
        }

        ret = positive?ret:-ret;
        if (ret > INT_MAX || ret < INT_MIN)
            return INT_MAX;
        else
            return ret;
    }
};
#endif
