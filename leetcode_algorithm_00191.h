#ifndef __leetcode_algorithm_00191_h__
#define __leetcode_algorithm_00191_h__
#include "basic_headers.h"
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int bits = sizeof(uint32_t) * 8;
        int weight = 0;
        for (int i = 0; i < bits; ++i) {
            if ((n & (1 << i)) != 0)
                ++weight;
        }
        return weight;
    }
};
#endif /*__leetcode_algorithm_00191_h__*/
