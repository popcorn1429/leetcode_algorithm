#ifndef __leetcode_algorithm_67_h__
#define __leetcode_algorithm_67_h__
#include <string>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        if (a.empty())
            return b;

        if (b.empty())
            return a;

        size_t len = a.size() < b.size() ? (b.size() + 2) : (a.size() + 2);
        char* pBuff = new char[len];
        memset(pBuff, 0, len);

        calcBinary(a, b, pBuff, len);

        
        return pBuff + calcBinary(a, b, pBuff, len);
    }

    int calcBinary(const string& a, const string& b, char* pBuff, size_t len) {
        int pos_a = a.size() - 1;
        int pos_b = b.size() - 1;
        int pos_p = len - 2;
        int r = 0;
        while (pos_a >= 0 || pos_b >= 0) {
            if (pos_a < 0) {
                if (r + b[pos_b] - '0' > 1) {
                    pBuff[pos_p] = '0';
                    r = 1;
                    --pos_p;
                    --pos_b;
                }
                else {
                    pBuff[pos_p] = r + b[pos_b];
                    r = 0;
                    --pos_p;
                    --pos_b;
                }
            }
            else if (pos_b < 0) {
                if (r + a[pos_a] - '0' > 1) {
                    pBuff[pos_p] = '0';
                    r = 1;
                    --pos_p;
                    --pos_a;
                }
                else {
                    pBuff[pos_p] = r + a[pos_a];
                    r = 0;
                    --pos_p;
                    --pos_a;
                }
            }
            else {
                int s = r + a[pos_a] - '0' + b[pos_b] - '0';
                r = s / 2;
                pBuff[pos_p] = s % 2 + '0';
                --pos_p;
                --pos_a;
                --pos_b;
            }
        }
        if (r != 0) {
            pBuff[pos_p] = r + '0';
            --pos_p;
        }

        return pos_p + 1;
    }
};
#endif