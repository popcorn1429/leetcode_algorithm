#ifndef __LEETCODE_ALGORITHM_12_H__
#define __LEETCODE_ALGORITHM_12_H__
/*
罗马数字共有7个，即I（1）、V（5）、X（10）、L（50）、C（100）、D（500）和M（1000）。
1、重复数次：一个罗马数字重复几次，就表示这个数的几倍。

2、右加左减：
2.1 在较大的罗马数字的右边记上较小的罗马数字，表示大数字加小数字。
2.2 在较大的罗马数字的左边记上较小的罗马数字，表示大数字减小数字。
2.3 左减的数字有限制，仅限于I、X、C。比如45不可以写成VL，只能是XLV
2.4 但是，左减时不可跨越一个位数。比如，99不可以用IC（100 - 1）表示，而是用XCIX（[100 - 10] + [10 - 1]）表示。（等同于阿拉伯数字每位数字分别表示。）
2.5 左减数字必须为一位，比如8写成VIII，而非IIX。
2.6 右加数字不可连续超过三位，比如14写成XIV，而非XIIII。（见下方“数码限制”一项。）
4.1 同一数码最多只能出现三次，如40不可表示为XXXX，而要表示为XL。

*/
#include <string>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        if (num <= 0 || num >= 4000)
            return string();

        string result;
        int cnt_m = num / 1000;
        if (cnt_m > 0)
            result.append(cnt_m, 'M');

        num %= 1000;
        toRoman_1000(num, result);
        return result;
    }

    //num < 1000
    void toRoman_1000(int num, string& result) {
        if (num >= 1000)
            return;

        if (num >= 900) {
            result.append("CM");
            num -= 900;
            toRoman_100(num, result);
            return;
        }

        int cnt_D = num / 500;
        if (cnt_D > 0)
            result.append(cnt_D, 'D');

        num %= 500;
        toRoman_500(num, result);
    }

    //num < 500
    void toRoman_500(int num, string& result) {
        if (num >= 500)
            return;

        if (num >= 400) {
            result.append("CD");

            num -= 400;
            toRoman_100(num, result);
        }
        else {
            int cnt_C = num / 100;
            if (cnt_C > 0)
                result.append(cnt_C, 'C');

            num %= 100;
            toRoman_100(num, result);
        }
    }

    //num < 100
    void toRoman_100(int num, string& result) {
        if (num >= 100)
            return;

        if (num >= 90) {
            result.append("XC");
            num -= 90;
            toRoman_10(num, result);
            return;
        }

        int cnt_L = num / 50;
        if (cnt_L > 0)
            result.append(cnt_L, 'L');

        num %= 50;
        toRoman_50(num, result);
    }

    //num < 50
    void toRoman_50(int num, string& result) {
        if (num >= 50)
            return;

        if (num >= 40) {
            result.append("XL");

            num -= 40;
            toRoman_10(num, result);
        }
        else {
            int cnt_X = num / 10;
            if (cnt_X > 0)
                result.append(cnt_X, 'X');

            num %= 10;
            toRoman_10(num, result);
        }
    }

    //num < 10
    void toRoman_10(int num, string& result) {
        if (num >= 10)
            return;

        if (num == 9)
            result.append("IX");
        else {
            int cnt_V = num / 5;
            if (cnt_V > 0)
                result.append(cnt_V, 'V');

            num %= 5;
            toRoman_5(num, result);
        }
    }

    //num < 5
    void toRoman_5(int num, string& result) {
        if (num >= 5)
            return;

        if (num >= 4) {
            result.append("IV");
        }
        else {
            if (num > 0)
                result.append(num, 'I');
        }
    }
};

#endif