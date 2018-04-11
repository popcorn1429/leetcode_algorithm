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
    enum class ExprType {
        Flexable,
        Fixed_Length,
        Precise_Content
    };

    struct ExprNode {
        ExprType    type;
        size_t      length;
        char*       expr;

        ExprNode() : type(ExprType::Flexable), length(0), expr(nullptr) { }
        ExprNode(size_t s) : type(ExprType::Fixed_Length), length(s), expr(nullptr) { }
        ExprNode(const char* p, size_t s) : type(ExprType::Precise_Content), length(s) {
            expr = new char[s + 1];
            _memccpy(expr, p, 0, s);
            expr[s] = '\0';
        }

        ExprNode(const ExprNode& node) : type(node.type), length(node.length) {
            if (type == ExprType::Precise_Content) {
                expr = new char[node.length + 1];
                _memccpy(expr, node.expr, 0, node.length);
                expr[length] = '\0';
            }
            else {
                expr = nullptr;
            }
        }

        ~ExprNode() {
            if (nullptr != expr) {
                delete[] expr;
                expr = nullptr;
            }
        }
    };

    size_t parseRegularExpr(const string& p) {
        const char* src = p.c_str();
        while (*src != '\0') {
            if (*src == '*') {
                nodes.push_back(ExprNode());
                while (*src == '*')
                    ++src;
            }
            else if (*src == '?') {
                size_t s = 0;
                while (*src == '?') {
                    ++src;
                    ++s;
                }
                nodes.push_back(ExprNode(s));
            }
            else {
                size_t s = 0;
                while (*src != '\0' && *src != '?' && *src != '*') {
                    ++src;
                    ++s;
                }
                nodes.push_back(ExprNode(src - s, s));
            }
        }
        return nodes.size();
    }

    void printNodes() {
        for (const ExprNode& node : nodes) {
            cout << "{ ";
            switch (node.type)
            {
            case ExprType::Flexable:
            cout << "*" << " }\n";
            break;
            case ExprType::Fixed_Length:
            cout << "?[" << node.length << "] }\n";
            break;
            case ExprType::Precise_Content:
            cout << node.expr << " }\n";
            break;
            default:
            break;
            }
        }
        cout << endl;
    }

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
        /*
        parseRegularExpr(p);
        printNodes();

        //return true;
        return isMatchStrictly(s.c_str(), nodes.cbegin());
        */
    }

    bool isMatchStrictly(const char* src, vector<ExprNode>::const_iterator itr) {
        if (itr == nodes.cend()) {
            return *src == '\0';
        }

        if (itr->type == ExprType::Flexable) {
            return isMatchLoosely(src, itr + 1);
        }
        else if (itr->type == ExprType::Fixed_Length) {
            size_t s = itr->length;
            while (s > 0 && *src != '\0') {
                ++src;
                --s;
            }

            if (s != 0)
                return false;
            else
                return isMatchStrictly(src, itr + 1);
        }
        else {
            if (strncmp(src, itr->expr, itr->length) != 0) {
                return false;
            }
            else {
                return isMatchStrictly(src + itr->length, itr + 1);
            }
        }
    }

    bool isMatchLoosely(const char* src, vector<ExprNode>::const_iterator itr) {
        if (itr == nodes.cend()) {
            return true;
        }

        if (itr->type == ExprType::Flexable) {
            return isMatchLoosely(src, itr + 1);
        }
        else if (itr->type == ExprType::Fixed_Length) {
            size_t s = itr->length;
            while (s > 0 && *src != '\0') {
                ++src;
                --s;
            }

            if (s != 0)
                return false;
            else
                return isMatchLoosely(src, itr + 1);
        }
        else {
            const char* found = strstr(src, itr->expr);
            while (found != nullptr) {
                if (isMatchStrictly(found + itr->length, itr + 1))
                    return true;
                else
                    found = strstr(found + 1, itr->expr);
            }

            return false;
        }
    }

    
private:
    vector<ExprNode>  nodes;
};

#endif