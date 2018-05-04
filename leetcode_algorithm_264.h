#ifndef _leetcode_algorithm_264_h_
#define _leetcode_algorithm_264_h_
#include "basic_headers.h"

using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        if (!init()) {
            return -1;
        }

        int result = 0;
        int i = 0;
        int num = 1;
        insert(num);
        while (true) {
            //if (nums[num] == '1') {
            if (check(num)) {
                ++i;
                if (i == n) {
                    result = num;
                    break;
                }

                int tmp = num;
                //nums[tmp << 1] = '1';
                insert(tmp << 1);
                tmp = num;
                //nums[tmp << 1 + num] = '1';
                insert((tmp << 1) + num);
                tmp = num;
                //nums[tmp << 2 + num] = '1';
                insert((tmp << 2) + num);
            }
            ++num;
        }
        
        return result;
    }   

    bool init() {
        nums = new(nothrow) char[MAX_CNT];
        if (nums == nullptr) {
            cout << "new failed~" << endl;
            return false;
        }

        memset(nums, 0, MAX_CNT);
        return true;
    }

    bool check(int num) {
        if (num < 0)
            return false;

        char c = nums[num / 8 + 1];
        switch (num % 8) {
        case 0:
            return (c & 0x80) != 0;
        case 1:
            return (c & 0x40) != 0;
        case 2:
            return (c & 0x20) != 0;
        case 3:
            return (c & 0x10) != 0;
        case 4:
            return (c & 0x08) != 0;
        case 5:
            return (c & 0x04) != 0;
        case 6:
            return (c & 0x02) != 0;
        case 7:
            return (c & 0x01) != 0;
        }
    }

    void insert(int num) {
        if (num < MAX_CNT * 8) {
            switch (num % 8) {
            case 0:
                nums[num / 8 + 1] |= 0x80;
            case 1:
                nums[num / 8 + 1] |= 0x40;
            case 2:
                nums[num / 8 + 1] |= 0x20;
            case 3:
                nums[num / 8 + 1] |= 0x10;
            case 4:
                nums[num / 8 + 1] |= 0x08;
            case 5:
                nums[num / 8 + 1] |= 0x04;
            case 6:
                nums[num / 8 + 1] |= 0x02;
            case 7:
                nums[num / 8 + 1] |= 0x01;
            }
        }
    }

private:
    static const unsigned long MAX_CNT = 1024*1024*512;
    char *nums;

};
#endif