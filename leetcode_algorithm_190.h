#ifndef __leetcode_algorithm_190_h__
#define __leetcode_algorithm_190_h__
#include "basic_headers.h"

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t reverse_number = 0;
        int bits = sizeof(uint32_t) * 8;
        for (int i = 0; i < bits; ++i) {
            if (i < 16)
                reverse_number |= (n & (1 << i)) << (31 - 2 * i);
            else
                reverse_number |= (n & (1 << i)) >> (2 * i - 31);
        }
        return reverse_number;
    }
};

#endif /*__leetcode_algorithm_190_h__*/
