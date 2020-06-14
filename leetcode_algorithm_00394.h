#pragma once
#include "basic_headers.h"

class Solution {
public:
    string decodeString(string s) {
        string result;
        convert(s, 0, s.size(), result);
        return result;
    }

    void convert(const string &s, size_t from, size_t to, string &result) {
        size_t pos = from;
        while (pos != to) {
            char c = s[pos];

            if (isalpha(c)) {
                size_t end = toAlphaEnd(s, pos);
                merge(result, s, pos, end);
                pos = end;
                continue;
            }
            else if (isdigit(c)) {
                size_t end = toNumberEnd(s, pos);
                size_t n = toNumber(s, pos, end);

                string unit;
                size_t convert_end = toConvertEnd(s, end);
                convert(s, end + 1, convert_end, unit);

                for (size_t i = 0; i < n; ++i) {
                    result.append(unit);
                }

                pos = convert_end;
                continue;
            }
            else {
                ++pos;
            }
        }
    }

    void merge(string &result, const string &s, size_t pos, size_t end) {
        while (pos != end) result.push_back(s[pos++]);
    }

    size_t toAlphaEnd(const string &s, size_t pos) {
        while (isalpha(s[pos])) ++pos;
        return pos;
    }

    size_t toNumberEnd(const string &s, size_t pos) {
        while (isdigit(s[pos])) ++pos;
        return pos;
    }

    size_t toConvertEnd(const string &s, size_t pos) {
        int i = 1;
        do {
            ++pos;
            if (s[pos] == '[') ++i;
            else if (s[pos] == ']') --i;
        } while (i != 0);
        return pos;
    }

    size_t toNumber(const string &s, size_t from, size_t to) {
        size_t n = 0;
        while (from != to) {
            n = n * 10 + (s[from] - '0');
            ++from;
        }
        return n;
    }

    inline bool isdigit(char c) {
        return '0' <= c && c <= '9';
    }

    inline bool isalpha(char c) {
        return ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z');
    }
};