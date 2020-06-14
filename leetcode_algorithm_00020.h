#ifndef __leetcode_algorithm_00020_h__
#define __leetcode_algorithm_00020_h__
#include <string>
using namespace std;
class Solution {
public:
    bool isValid(string s) {

        char buff[4096];
        const char* str = s.c_str();
        char* p = buff;
        const char* pStr = str;
        while (*pStr != '\0') {
            switch (*pStr) {
            case '(':
            case '{':
            case '[':
                *p = *pStr;
                ++p;
                break;
            case ')':
            case '}':
            case ']':
                if (match(buff, p, *pStr)) {
                    --p;
                }
                else {
                    return false;
                }
                break;
            default:
                break;
            }
            ++pStr;
        }

        return p == buff;
    }

    bool match(const char* buff, char* p, char c) {
        if (p == buff)
            return false;

        if ((*(p - 1) == '(' && c == ')')
            || (*(p - 1) == '[' && c == ']') || (*(p - 1) == '{' && c == '}')) {
            return true;
        }
        else
            return false;
    }
};
#endif
