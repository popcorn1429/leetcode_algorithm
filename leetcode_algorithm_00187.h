#pragma once
#include "basic_headers.h"

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        size_t sz = s.size();
        if (sz <= 10) return {};

        map<char, int> nucletides{ {'A', 0},{'C', 1},{'G', 2},{'T', 3} };

        vector<string> result;
        set<int> existed;
        set<int> saved;
        for (size_t start = 0; start < sz - 9; ++start) {
            int v = calc(s, start, nucletides);
            if (v == -1) break;
            if (existed.find(v) != existed.end()) {
                if (saved.find(v) == saved.end()) {
                    result.push_back(string(s, start, 10));
                    saved.insert(v);
                }
            }
            else {
                existed.insert(v);
            }
        }

        return result;
    }

    int calc(const string &s, size_t start, const map<char, int> &nucletides) {
        if (start + 10 > s.size()) return -1;
        int v = 0;
        for (size_t i = 0; i < 10; ++i) {
            v = v * 4 + (nucletides.at(s[start + i]));
        }
        return v;
    }
};