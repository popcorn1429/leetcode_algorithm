#ifndef __leetcode_algorithm_00017_h__
#define __leetcode_algorithm_00017_h__
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.find('0') != string::npos || digits.find('1') != string::npos) {
            return vector<string>();
        }

        auto sz = digits.size();
        char *element = new char[sz+1];
        memset(element, 0, sz + 1);

        vector<string> result;
        auto cnt = 1;
        for (char c : digits) {
            if ('7' == c || '9' == c) {
                cnt << 2;
            }
            else {
                cnt *= 3;
            }
        }
        result.reserve(cnt);
        combine(digits, 0, element, result);
        return result;
    }

    void combine(const string& digits, string::size_type pos, char* element, vector<string>& result) {
        if (pos >= digits.size())
            return;

        char curDigit = digits[pos];
        const char* alphas = getAlpha(curDigit);
        if (alphas != nullptr) {
            const char* p = alphas;
            while (*p != '\0') {
                element[pos] = *p;
                if (pos == digits.size()-1) {
                    result.push_back(element);
                }
                else {
                    combine(digits, pos + 1, element, result);
                }
                ++p;
            }
        }
    }

    const char* getAlpha(char c) {
        static char two[4]   = { 'a', 'b', 'c', '\0' };
        static char three[4] = { 'd', 'e', 'f', '\0' };
        static char four[4]  = { 'g', 'h', 'i', '\0' };
        static char five[4]  = { 'j', 'k', 'l', '\0' };
        static char six[4]   = { 'm', 'n', 'o', '\0' };
        static char seven[5] = { 'p', 'q', 'r', 's', '\0' };
        static char eight[4] = { 't', 'u', 'v', '\0' };
        static char nine[5]  = { 'w', 'x', 'y', 'z', '\0' };

        switch (c)
        {
        case '2':
            return two;
        case '3':
            return three;
        case '4':
            return four;
        case '5':
            return five;
        case '6':
            return six;
        case '7':
            return seven;
        case '8':
            return eight;
        case '9':
            return nine;
        default:
            break;
        }
        return nullptr;
    }

};

#endif
