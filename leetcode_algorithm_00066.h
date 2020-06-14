#ifndef __leetcode_algorithm_00066_h__
#define __leetcode_algorithm_00066_h__
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int r = 1;
        for (int i = digits.size() - 1; i >= 0; --i) {
            ++digits[i];
            if (digits[i] > 9) {
                r = 1;
                digits[i] -= 10;
            }
            else {
                r = 0;
                break;
            }
        }

        vector<int> result;
        if (r == 1) {
            result.push_back(1);
        }

        for (int n : digits) {
            result.push_back(n);
        }

        return result;
    }
};
#endif
