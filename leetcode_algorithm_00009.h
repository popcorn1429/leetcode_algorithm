#ifndef _leetcode_algorithm_00009_h_
#define _leetcode_algorithm_00009_h_

#include <iostream>
using namespace std;

bool isPalindrome(int x) {
    int n = x;
    int m = 0;
    while (n != 0) {
        m *= 10;
        m += (n % 10);
        n /= 10;
    }

    return (m == x || m == -x);
}

#endif /*_leetcode_algorithm_00009_h_*/
