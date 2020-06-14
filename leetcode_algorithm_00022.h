#ifndef __leetcode_algorithm_00022_h__
#define __leetcode_algorithm_00022_h__
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        char *buff = new char[n * 2 + 1];
        memset(buff, 0, n * 2 + 1);

        vector<string> result;
        generate(buff, n, 0, 0, result);
        return result;
    }

    void generate(char* buff, const int n, int i, int j, vector<string>& result) {
        if (i == n) {
            while (j < i) {
                buff[i + j] = ')';
                ++j;
            }
            result.push_back(buff);
            return;
        }

        if (i < n) {
            buff[i + j] = '(';
            generate(buff, n, i + 1, j, result);

            if (j < i) {
                buff[i + j] = ')';
                generate(buff, n, i, j + 1, result);
            }
        }
    }
};



#endif
