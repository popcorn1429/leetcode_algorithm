#pragma once
#include "basic_headers.h"

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        int sz = s.size();
        vector<string> result;
        int segpos[5] = { 0, 0, 0, 0, sz };
        parse(s, segpos, 1, result);
        return result;
    }

    void parse(const string &str, int segpos[], int pos, vector<string> &result) {
        if (pos <= 0) return;
        if (pos == 4) {
            if (checkValid(str, segpos[3], str.size())) {
                result.push_back(to_ip(str, segpos));
                return;
            }
        }

        for (int i = 1; i <= 3; ++i) {
            int remain = str.size() - segpos[pos - 1] - i;

            if (remain < (4 - pos) || remain > 3 * (4 - pos))
                continue;

            if (checkValid(str, segpos[pos - 1], segpos[pos - 1] + i)) {
                segpos[pos] = segpos[pos - 1] + i;
                parse(str, segpos, pos + 1, result);
            }
        }
    }

    string to_ip(const string &str, int segpos[]) {
        string ip(str.size() + 3, '0');

        for (int k = 0; k < 4; ++k) {
            for (int i = segpos[k]; i < segpos[k + 1]; ++i) {
                ip[k + i] = str[i];
            }
            if (k != 3) ip[segpos[k + 1] + k] = '.';
        }
        return ip;
    }

    bool checkValid(const string &str, int start, int end) {
        if (end - start <= 0 || end - start > 3) return false;

        if (str[start] == '0') {
            return (end - start == 1);
        }

        if (end - start < 3) return true;

        if (str[start] > '2') return false;
        if (str[start] < '2') return true;
        if (str[start + 1] > '5') return false;
        if (str[start + 1] < '5') return true;
        if (str[start + 2] > '5') return false;
        return true;
    }
};