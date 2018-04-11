#ifndef _leetcode_algorithm_264_h_
#define _leetcode_algorithm_264_h_
#include <bitset>
using namespace std;

class Solution {
public:
    Solution() :ready(false){}

    int nthUglyNumber(int n) {
        initBits();

        int j = 0;
        for (int i = 1; i < bits.size(); ++i) {
            if (bits.test(i)) {
                ++j;
                if (j == n)
                    return i;
            }
        }
    }

    void initBits() {
        if (ready)
            return;

        bits.set(1);
        for (int i = 2; i < bits.size(); i += 2){
            bits.set(i);
        }
        for (int i = 3; i < bits.size(); i += 3){
            bits.set(i);
        }
        for (int i = 5; i < bits.size(); i += 5){
            bits.set(i);
        }
        ready = true;
    }

private:
    bitset<4000> bits;
    bool         ready;
};
#endif