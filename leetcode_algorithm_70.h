#ifndef __leetcode_algorithm_70_h__
#define __leetcode_algorithm_70_h__
#include <vector>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n == 1)
            return 1;
        else if (n == 2)
            return 2;
        else
            return climbStairs_aux(n);
    }

    //n > 2
    int climbStairs_aux(int n) {
        ways.resize(n);
        ways[0] = 1;
        ways[1] = 2;
        for (int i = 2; i < n; ++i) {
            ways[i] = ways[i - 1] + ways[i - 2];
        }
        return ways[n - 1];
    }

private:
    vector<int> ways;

};
#endif