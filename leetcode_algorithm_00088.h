#ifndef __leetcode_algorithm_00088_h__
#define __leetcode_algorithm_00088_h__
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int insert_pos = n + m - 1;
        while (n > 0 || m > 0) {
            if (n == 0) {
                nums1[insert_pos] = nums1[m-1];
                --insert_pos;
                --m;
            }
            else if (m == 0) {
                nums1[insert_pos] = nums2[n-1];
                --insert_pos;
                --n;
            }
            else {
                if (nums1[m-1] < nums2[n-1]) {
                    nums1[insert_pos] = nums2[n-1];
                    --insert_pos;
                    --n;
                }
                else {
                    nums1[insert_pos] = nums1[m-1];
                    --insert_pos;
                    --m;
                }
            }
        }
    }
};
#endif
