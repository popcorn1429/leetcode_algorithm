/*

The set [1,2,3,...,n] contains a total of n! unique permutations.
By listing and labeling all of the permutations in order,
we get the following sequence for n = 3:
 "123"
 "132"
 "213"
 "231"
 "312"
 "321"
Given n and k, return the kth permutation sequence.

Example:
  Input: n = 3, k = 3
  Output: "213"
*/

#ifndef _leetcode_algorithm_00060_h_
#define _leetcode_algorithm_00060_h_
#include "basic_headers.h"

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> factorials;
        getFactorials(n, factorials);

        string src(n, '0');
        for (int i = 0; i < n; ++i) {
            src[i] += i + 1;
        }
        
        string result;
        for (int index = 0; index < n; ++index) {
            appendChar(src, result, n, index, k, factorials);
        }
        return result;
    }

    void getFactorials(int n, vector<int>& factorials) {
        factorials.push_back(1);
        int r = 1;
        for (int i = 1; i <= n; ++i) {
            r *= i;
            factorials.push_back(r);
        }
    }

    void appendChar(string& src, string& result, int n, int index, int& k, const vector<int>& factorials) {
        int factor = factorials[n - index - 1];
        int m = (k-1) / factor;
        int r = k - (m*factor);
        for (int i = 0; i < src.size(); ++i) {
            if (src[i] != '0') {
                if (m == 0) {
                    result += src[i];
                    src[i] = '0';
                    break;
                }
                --m;
            }
        }
        k = r;
    }
};

#endif /*_leetcode_algorithm_00060_h_*/
