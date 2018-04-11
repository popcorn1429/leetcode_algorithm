#ifndef _leetcode_algorithm_49_h_
#define _leetcode_algorithm_49_h_
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> v;
        map<string, size_t> r;
        for (const auto& str : strs) {
            string s{ str };
            stringQuickSort(s);
            if (r.find(s) != r.end()) {
                v[r[s]].push_back(str);
            }
            else {
                v.push_back(vector<string>());
                v[v.size() - 1].push_back(str);
                r.insert(make_pair(s, v.size() - 1));
            }
        }
        return v;
    }

    void stringQuickSort(string& src) {
        char *p = new char[src.size() + 1];
        _memccpy(p, src.c_str(), 0, src.size());
        p[src.size()] = '\0';
        qsort(p, src.size(), sizeof(char), [](const void* pa, const void* pb)->int{ return *static_cast<const char*>(pa)-*static_cast<const char*>(pb); });
        src = p;
    }
};
#endif