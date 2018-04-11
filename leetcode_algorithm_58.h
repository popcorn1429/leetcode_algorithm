#ifndef __leetcode_algorithm_58_h__
#define __leetcode_algorithm_58_h__
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s.empty())
            return 0;

        int last_pos = s.size()-1;
        int len = 0;
        while (last_pos >= 0) {
            if (s[last_pos] == ' ') {
                if (len == 0)
                    --last_pos;
                else
                    break;
            }
            else {
                ++len;
                --last_pos;
            }
        }
        return len;
    }
};
#endif