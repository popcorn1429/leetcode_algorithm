/*
Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true

scientific notation (Mantissa)E(Exponent):
   Mantissa can be positive or negative  (+2.5e3  -1.2e4 ...)
   Exponent can be positive or negative  ( 4e+5   3e-2 ... )
   Mantissa and Exponent only can be decimal number
   Exponent must be an integer number (without dot)

decimal :
   can be positive or negative  ( +3  -2  ...)
   can have one dot             ( 5.3 ...)

octonary :
   no dot
   can be positive or negative  (+057  -032 ...)

hexadecimal :
   no dot
   can be positive or negative  (+0xFA  -0x0C ...)

----------------------------------------------------------

The funny thing is, this question doesn't need to deal with octonary and 
hexadecimal.
*/

#ifndef _leetcode_algorithm_00065_h_
#define _leetcode_algorithm_00065_h_
#include "basic_headers.h"
class Solution {
public:
    bool isNumber(string s) {
        const char* src = s.c_str();
        bool isValidNumber = false;

        while (' ' == *src || '\t' == *src) {
            ++src;
        }
        
        /*
        return (isHexadecimal(src)
            || isScientificNotation(src))
            || isOctonary(src)
            || isDecimal(src);
        */
        return isScientificNotation(src)
            || isDecimal(src);
    }

    bool isDecimal(const char* src) {
        //start with + or - is ok,just skip it.
        if (*src == '+' || *src == '-')
            ++src;

        bool hasDigit = false;
        bool hasDot = false;
        bool hasBlank = false;
        const char* p = src;
        while (*p != '\0') {
            if (' ' == *p || '\t' == *p)
                hasBlank = true;
            else if (hasBlank)
                return false;
            else if ('.' == *p) {
                if (hasDot)
                    return false;

                hasDot = true;
            }
            else if (isDecimalChar(*p))
                hasDigit = true;
            else
                return false;

            ++p;
        }
        return hasDigit;
    }

    bool isOctonary(const char* src) {
        //start with + or - is ok,just skip it.
        if (*src == '+' || *src == '-')
            ++src;

        if (*src != '0')
            return false;  //should start with 0
        ++src;

        bool hasBlank = true;
        bool hasDigit = false;
        const char* p = src;
        while ('\0' != *p) {
            if (' ' == *p || '\t' == *p)
                hasBlank = true;
            else if (hasBlank)
                return false;
            else if (isOctonaryChar(*p))
                hasDigit = true;
            else
                return false;

            ++p;
        }
        return hasDigit;
    }

    bool isHexadecimal(const char* src) {
        //start with + or - is ok,just skip it.
        if (*src == '+' || *src == '-')
            return false;

        if (!('0' == *src && ('x' == *(src+1) || 'X' == *(src+1))))
            return false;  //should start with 0x or 0X
        src += 2;

        bool hasBlank = false;
        bool hasDigit = false;
        const char* p = src;
        while ('\0' != *p) {
            if (' ' == *p || '\t' == *p)
                hasBlank = true;
            else if (hasBlank)
                return false;
            else if (isHexadecimalChar(*p))
                hasDigit = true;
            else
                return false;

            ++p;
        }
        return hasDigit;
    }

    bool isScientificNotation(const char* src) {
        const char* pE = src;
        while (*pE != '\0') {
            if (*pE == 'e' || *pE == 'E')
                break;
            ++pE;
        }

        return (isMantissa(src, pE) && isExponent(pE + 1));
    }

    bool isMantissa(const char* src, const char* tail) {
        if ('+' == *src || '-' == *src)
            ++src;

        bool hasBlank = false;
        bool hasDecimal = false;
        bool hasDot = false;
        while ('\0' != *src && src != tail) {
            if (' ' == *src || '\t' == *src)
                return false;
            else if ('.' == *src) {
                if (hasDot)
                    return false;
                hasDot = true;
            }
            else if (isDecimalChar(*src))
                hasDecimal = true;
            else
                return false;

            ++src;
        }

        return hasDecimal;
    }

    bool isExponent(const char* src) {
        if ('+' == *src || '-' == *src)
            ++src;

        bool hasBlank = false;
        bool hasDecimal = false;
        while (*src != '\0') {
            if (' ' == *src || '\t' == *src)
                hasBlank = true;
            else if (hasBlank)
                return false;
            else if (isDecimalChar(*src))
                hasDecimal = true;
            else
                return false;

            ++src;
        }

        return hasDecimal;
    }


private:
    inline bool isDecimalChar(const char c) {
        return '0' <= c && c <= '9';
    }

    inline bool isOctonaryChar(const char c) {
        return '0' <= c && c <= '7';
    }

    inline bool isHexadecimalChar(const char c) {
        return ('0' <= c && c <= '9')
            || ('A' <= c && c <= 'F')
            || ('a' <= c && c <= 'f');
    }
};
#endif /*_leetcode_algorithm_00065_h_*/
