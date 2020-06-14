#ifndef __leetcode_algorithm_00014_h__
#define __leetcode_algorithm_00014_h__
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        auto cnt = strs.size();

        if (cnt == 0)
            return string();
        else if (cnt == 1)
            return strs[0];

        int pos = 0;
        bool allsame = true;
        const string& first = strs[0];

        do {
            const char * curChar = (first.c_str() + pos);
            if (curChar == '\0')
                break;

            for (decltype(cnt) i = 1; i < cnt; ++i) {
                const char * c = (strs[i].c_str() + pos);
                if (*c == '\0' || *c != *curChar) {
                    allsame = false;
                    break;
                }
            }

            if (allsame)
                ++pos;
        } while (allsame);
        
        return first.substr(0, pos);
    }
};


#endif
