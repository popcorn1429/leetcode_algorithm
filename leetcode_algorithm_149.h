/*Max Points on a Line*/
/*
Given n points on a 2D plane, 
find the maximum number of points that lie on the same straight line.
*/

#ifndef __leetcode_algorithm_149_h_
#define __leetcode_algorithm_149_h_
#include <map>
#include <set>
#include <vector>
#include <list>
#include <string>
#include <iostream>
using namespace std;

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}

    friend ostream& operator<<(ostream& o, const Point& point) {
        return o << "(" << point.x << ", " << point.y << ")";
    }
};

int gcd(int x, int y) {
    int _min = x < y ? x : y;
    int _max = x < y ? y : x;
    while (_min != 0) {
        int tmp = _min;
        _min = _max % _min;
        _max = tmp;
    }

    return _max;
}

struct Line {
    int k_y;
    int k_x;
    int c_y;
    int c_x;

    Line(int ky, int kx, int cy) {
        int kd = gcd(ky, kx);
        if (kd != 0) {
            k_y = ky / kd;
            k_x = kx / kd;
        }
        else {
            if (ky != 0) {
                k_y = 1;
                k_x = 0;
            }
            else {
                k_y = 0;
                k_x = 1;
            }
        }

        int cd = gcd(cy, kx);
        if (cd != 0) {
            c_y = cy / cd;
            c_x = kx / cd;
        }
        else {
            if (cy != 0) {
                c_y = 1;
                c_x = 0;
            }
            else {
                c_y = 0;
                c_x = 1;
            }
        }
    }

    bool operator<(const Line& l) const {
        bool bRet = true;
        do {
            if (k_x != l.k_x) {
                bRet = (k_x < l.k_x);
                break;
            }

            if (k_y != l.k_y) {
                bRet = (k_y < l.k_y);
                break;
            }

            if (c_x != l.c_x) {
                bRet = (c_x < l.c_x);
                break;
            }

            bRet = (c_y < l.c_y);
        } while (0);

        return bRet;
    }

    bool pointInLine(const Point& point) const {
        return k_y*point.x*c_x + c_y*k_x == k_x*c_x*point.y;
    }
};


class Solution {
public:
    int maxPoints(vector<Point>& points) {
        map<Line, int> results;

        for (auto itr = points.begin(); itr != points.end(); ++itr) {
            for (auto iter = itr + 1; iter != points.end(); ++iter) {
                if (!samePoint(*iter, *itr)) {
                    Line l(iter->y - itr->y, iter->x - itr->x, iter->x*itr->y - itr->x*iter->y);
                    if (results.find(l) != results.end()) {
                        results.insert(make_pair(l, 0));
                    }
                }
            }
        }

        if (results.empty())
            return points.size();

        for (auto iter = points.begin(); iter != points.end(); ++iter) {
            for (auto itr = results.begin(); itr != results.end(); ++itr) {
                if (itr->first.pointInLine(*iter))
                    ++itr->second;
            }
        }

        int iMaxPoints = 0;
        for (auto itr = results.begin(); itr != results.end(); ++itr) {
            if (iMaxPoints < itr->second)
                iMaxPoints = itr->second;
        }

        return iMaxPoints;
    }

    bool samePoint(const Point& _first, const Point& _second) const {
        return _first.x == _second.x && _first.y == _second.y;
    }
};
#endif /*__leetcode_algorithm_149_h_*/