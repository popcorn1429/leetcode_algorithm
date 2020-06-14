#ifndef __leetcode_algorithm_00028_h__
#define __leetcode_algorithm_00028_h__
#include <string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        auto sz_needle = needle.size();
        auto sz_haystack = haystack.size();
        if (sz_needle > sz_haystack)
            return -1;

        if (sz_needle == 0)
            return 0;
        
        for (string::size_type pos = 0; pos <= sz_haystack - sz_needle; ++pos) {
            if (haystack[pos] == needle[0]) {
                if (isMatch(haystack, pos, needle, sz_needle)) {
                    return static_cast<int>(pos);
                }
            }
        }
        return -1;
    }

    bool isMatch(const string& haystack, string::size_type pos, const string& needle, string::size_type sz_needle) {
        for (string::size_type i = 1; i != sz_needle; ++i) {
            if (haystack[pos + i] != needle[i])
                return false;
        }
        return true;
    }
};
#endif
