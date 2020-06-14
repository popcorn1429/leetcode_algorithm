/*Max Points on a Line*/
/*
Given n points on a 2D plane, 
find the maximum number of points that lie on the same straight line.
*/

#ifndef __leetcode_algorithm_00149_h__
#define __leetcode_algorithm_00149_h__
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

int abs(int x) {
    return x < 0 ? -x : x;
}

long gcd(long x, long y) {
    if (x == 0 || y == 0) {
        return 1;
    }

    long _min = x < y ? x : y;
    long _max = x < y ? y : x;
    while (_min != 0) {
        int tmp = _min;
        _min = _max % _min;
        _max = tmp;
    }

    return abs(_max);
}

struct Line {
    long long x;
    long long y; //why long long ,not int or long?
                 //because y would be (int*int-int*int),and maybe int is quite big
                 //and sometimes, sizeof(long) == sizeof(int) == 4
                 //use long long is safer.
    //dy/dx presents k
    int dy;
    int dx;

    Line(int a, int b, int c, int d)
    {
        dy = d - b;
        dx = c - a;

        if (dx == 0) {
            //vertical line : x = a
            x = a;
            y = 0;
            dy = 1;
        }
        else if (0 == dy) {
            //line : y = b
            x = 1;
            y = b;
            dx = 1;
        }
        else {
            //line : y = kx + b
            //k = dy/dx, b = (c*b - d*a)/(c - a) = y/x
            if (dy < 0) {
                dy = -dy;
                dx = -dx;
            }

            int tmp = static_cast<int>(gcd(dy, dx));
            dy /= tmp;
            dx /= tmp;

            y = c*b - static_cast<long long>(d)*a;
            x = c - a;
            if (0 == y) {
                x = 1;
            }
            else{
                if (y < 0) {
                    y = -y;
                    x = -x;
                }

                long temp = gcd(y, x);
                y /= temp;
                x /= temp;
            }
        }
    }

    bool operator<(const Line& l) const {
        do {
            if (x != l.x)
                return x < l.x;

            if (y != l.y)
                return y < l.y;

            if (dx != l.dx)
                return dx < l.dx;

            return dy < l.dy;
        } while (0);
    }

    bool pointInLine(const Point& point) const {
        if (dy == 0) {
            return point.y == y;
        }
        else if (dx == 0) {
            return point.x == x;
        }
        else {
            return x*dy*point.x + dx*y == x*dx*point.y;
        }
    }

    friend ostream& operator<<(ostream& o, const Line& line) {
        return o << "k:" << line.dy << "/" << line.dx << ",b:" << line.y << "/" << line.x;
    }
};

class Solution {
public:
    int maxPoints(vector<Point>& points) {
        map<Line, int> results;

        for (auto itr = points.begin(); itr != points.end(); ++itr) {
            for (auto iter = itr + 1; iter != points.end(); ++iter) {
                if (!samePoint(*itr, *iter)) {
                    Line l(itr->x, itr->y, iter->x, iter->y);
                    //cout << "line:" << l << endl;
                    if (results.find(l) == results.end()) {
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
#endif /*__leetcode_algorithm_00149_h__*/
