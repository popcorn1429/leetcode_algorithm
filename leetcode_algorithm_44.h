/*
Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

Note:

s could be empty and contains only lowercase letters a-z.
p could be empty and contains only lowercase letters a-z, and characters like ? or *.

*/

#ifndef __leetcode_algorithm_44_h__
#define __leetcode_algorithm_44_h__
#include <string>
#include <cstdio>
#include <vector>
#include <list>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p)
    {
        return isMatch(s.c_str(), p.c_str());
    }

    bool isMatch(const char* s, const char* p) {
        bool b = false;
        const char* start_s = nullptr;
        const char* start_p = nullptr;
        while (*s) {
            if (*s == *p || *p == '?') {
                ++s;
                ++p;
                continue;
            }

            if (*p == '*') {
                ++p;
                start_p = p;
                start_s = s;
                continue;
            }

            if (start_s != nullptr && (*start_s != '\0')) {
                ++start_s;
                s = start_s;
                p = start_p;
                continue;
            }
            
            return false;
        }

        while (*p == '*')
            ++p;

        return *p == '\0';
    }
    /*
    bool isMatch(const char* s, const char* p)
    {
        const char* star = NULL;
        const char* ss = s;
        while (*s){
            //advancing both pointers when (both characters match) or ('?' found in pattern)
            //note that *p will not advance beyond its length 
            if ((*p == '?') || (*p == *s)){ s++; p++; continue; }

            // * found in pattern, track index of *, only advancing pattern pointer 
            if (*p == '*'){ star = p++; ss = s; continue; }

            //current characters didn't match, last pattern pointer was *, current pattern pointer is not *
            //only advancing pattern pointer
            if (star){ p = star + 1; s = ++ss; continue; }

            //current pattern pointer is not star, last patter pointer was not *
            //characters do not match
            return false;
        }

        //check for remaining characters in pattern
        while (*p == '*'){ p++; }

        return !*p;
        
    }
    */
private:

};

#endif