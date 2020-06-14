#ifndef _leetcode_algorithm_00263_h_
#define _leetcode_algorithm_00263_h_

class Solution {
public:
    bool isUgly(int num) {
        if (1 == num || 2 == num || 3 == num || 5 == num)
            return true;

        if (num % 2 == 0)
            return isUgly(num / 2);
        else if (num % 3 == 0)
            return isUgly(num / 3);
        else if (num % 5 == 0)
            return isUgly(num / 5);
        else
            return false;
    }
};

#endif
