#pragma once
#include "basic_headers.h"

class Solution {
public:
    vector<int> grayCode(int n) {
        if (n == 0) return { 0 };
        if (1 == n) return { 0, 1 };
        if (2 == n) return { 0, 1, 3, 2 };

        vector<int> changebits(1 << n);
        changebits[0] = -1;
        changebits[1] = 0;
        changebits[2] = 1;
        changebits[3] = 0;
        changebits[4] = 2;
        changebits[5] = 0;
        changebits[6] = 1;
        changebits[7] = 0;
        int curn = 3;
        while (curn < n) {
            extendChangebits(changebits, changebits.size(), curn);
            ++curn;
        }

        vector<int> values(1 << n);
        getvalues(n, changebits, values);
        return values;
    }

    bool extendChangebits(vector<int> &changebits, size_t cap, int curn) {
        size_t cursz = 0x0001 << curn;
        size_t half = cursz >> 1;
        size_t nextsz = cursz << 1;
        if (cap < nextsz) return false;
        changebits[cursz] = curn;
        changebits[cursz + 1] = 0;
        changebits[cursz + 2] = 1;
        changebits[cursz + 3] = 0;

        for (size_t i = 0; i < half; ++i) {
            changebits[cursz + 4 + i] = changebits[half + i];
        }

        for (size_t i = 0; i < half - 4; ++i) {
            changebits[cursz + half + 4 + i] = changebits[half + i];
        }
        return true;
    }

    void getvalues(int n, vector<int> &changebits, vector<int> &values) {
        int cur = 0;
        int index = 0;
        for (int index = 0; index < (1 << n); ++index) {
            cur = getNextValue(cur, changebits, index);
            values[index] = cur;
        }

    }

    int getNextValue(int cur, vector<int> &changebits, int index) {
        if (changebits[index] < 0) return cur;

        int flag = 0x01 << changebits[index];
        if (cur & flag) {
            return cur & (~flag);
        }
        else {
            return cur | flag;
        }
    }
};