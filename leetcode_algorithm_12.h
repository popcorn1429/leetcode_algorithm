#ifndef __LEETCODE_ALGORITHM_12_H__
#define __LEETCODE_ALGORITHM_12_H__
/*
�������ֹ���7������I��1����V��5����X��10����L��50����C��100����D��500����M��1000����
1���ظ����Σ�һ�����������ظ����Σ��ͱ�ʾ������ļ�����

2���Ҽ������
2.1 �ڽϴ���������ֵ��ұ߼��Ͻ�С���������֣���ʾ�����ּ�С���֡�
2.2 �ڽϴ���������ֵ���߼��Ͻ�С���������֣���ʾ�����ּ�С���֡�
2.3 ��������������ƣ�������I��X��C������45������д��VL��ֻ����XLV
2.4 ���ǣ����ʱ���ɿ�Խһ��λ�������磬99��������IC��100 - 1����ʾ��������XCIX��[100 - 10] + [10 - 1]����ʾ������ͬ�ڰ���������ÿλ���ֱַ��ʾ����
2.5 ������ֱ���Ϊһλ������8д��VIII������IIX��
2.6 �Ҽ����ֲ�������������λ������14д��XIV������XIIII�������·����������ơ�һ���
4.1 ͬһ�������ֻ�ܳ������Σ���40���ɱ�ʾΪXXXX����Ҫ��ʾΪXL��

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