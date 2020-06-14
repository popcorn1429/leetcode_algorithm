#ifndef __leetcode_algorithm_00069_h__
#define __leetcode_algorithm_00069_h__
#include <cstdio>
#include <cstdlib>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        char number[16] = { 0 };
        int n = sprintf_s(number, sizeof(number), "%d", x);
        int remainder = 0;
        int devidend = 0;
        int p = 0;
        if (n % 2 == 0) {
            devidend = (number[0] - '0') * 10 + (number[1] - '0'); // 10 -- 99
            p = 2;
        }
        else {
            devidend = number[0] - '0';  //1 -- 9
            p = 1;
        }
        int root = sqrtBelow100(devidend);
        remainder = devidend - root*root;
        return calc(number, n, p, remainder, root);
    }

private:
    //s : [1,99]
    int sqrtBelow100(int s) {
        if (s < 1)
            return 0;
        else if (s < 4)
            return 1;
        else if (s < 9)
            return 2;
        else if (s < 16)
            return 3;
        else if (s < 25)
            return 4;
        else if (s < 36)
            return 5;
        else if (s < 49)
            return 6;
        else if (s < 64)
            return 7;
        else if (s < 81)
            return 8;
        else
            return 9;
    }

    int calc(char number[], int n, int pos, int remainder, int root) {
        if (pos >= n)
            return root;

        int dividend = remainder * 100 + (number[pos] - '0') * 10 + (number[pos + 1] - '0');
        int m = dividend / (20 * root);
        if (m*(root * 20 + m) > dividend) {
            --m;
        }

        return calc(number, n, pos + 2, dividend - m*(root * 20 + m), root * 10 + m);
    }
};
#endif
