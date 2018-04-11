#ifndef __leetcode_algorithm_53_h__
#define __leetcode_algorithm_53_h__
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int max_sum = 0;
        int max_n = INT_MIN;
        bool found = false;
        for (const auto& i : nums) {
            if (max_n < i)
                max_n = i;

            if (sum + i > 0) {
                sum += i;
                if (sum > max_sum) {
                    found = true;
                    max_sum = sum;
                }
            }
            else {
                sum = 0;
            }
        }
        
        return found ? max_sum : max_n;
    }
};
#endif