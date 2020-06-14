#pragma once
#include "basic_headers.h"

class Solution {
public:
    bool isHappy(int n) {
        set<int> route;

        int i = n;
        route.insert(i);
        while (i != 1) {
            i = transform(i);
            if (1 == i) return true;
            if (route.find(i) != route.end()) return false;

            route.insert(i);
        }
        return true;
    }

    int transform(int n) {
        int result = 0;
        while (n > 0) {
            int r = n % 10;
            result += (r * r);
            n /= 10;
        }
        return result;
    }
};