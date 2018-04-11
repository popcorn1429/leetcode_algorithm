#ifndef __leetcode_algorithm_38_h__
#define __leetcode_algorithm_38_h__
#include <string>
using namespace std;
class Solution {
public:
    string countAndSay(int n) {
        if (n < 1)
            return "";
        if (n == 1)
            return "1";

        string arr[2] = { "1", "" };
        for (int i = 1; i < n; ++i) {
            readAndSay(arr[(1 + i) % 2], arr[i % 2]);
        }

        return arr[(n + 1) % 2];
    }

    void readAndSay(const string& src, string& result) {
        result.clear();
        char c = '\0';
        int cnt = 0;
        char strCnt[16] = { 0 };
        for (size_t i = 0; i < src.size(); ++i) {
            if (src[i] == c) ++cnt;
            else {
                if (cnt != 0) {
                    result.append(to_string(cnt));
                    result.append(1, c);
                }
                c = src[i];
                cnt = 1;
            }
        }

        if (cnt != 0) {
            result.append(to_string(cnt));
            result.append(1, c);
        }
    }
};
#endif