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

class Solution {
public:
    int maxPoints(vector<Point>& points) {
        if (points.size() <= 2)
            return points.size();

        //remove duplicate points
        distinctPoinsts(points);

        int maxCount = 0;
        vector<set<int> >::iterator itr = lines.begin();
        for (long i = 0; i < points.size() - 1; ++i) {
            for (long j = i+1; j < points.size(); ++j) {
                
                int cnPoints = selectPointsInLine(points, i, j, itr);
                if (cnPoints > maxCount) {
                    maxCount = cnPoints;
                }
            }
        }


        return maxCount;
    }

    int selectPointsInLine(const vector<Point>& points, int i, int j, vector<set<int> >::iterator& itr) {
        for (itr = lines.begin(); itr != lines.end(); ++itr) {
            if (itr->find(i) != itr->end()) {
                if (itr->find(j) != itr->end()) {
                    return itr->size();
                }
                else {
                    if (checkPointInLine(points, j, *itr)) {
                        itr->insert(j);

                        //for test...
                        cout << "one line : \n";
                        for (auto iter = itr->cbegin(); iter != itr->cend(); ++iter) {
                            cout << points[*iter] << ",";
                        }
                        cout << endl;

                        return itr->size();
                    }
                }
            }
        }

        lines.push_back({ i, j });
        itr = lines.begin();
        return 2;
    }

    bool checkPointInLine(const vector<Point>& points, int j, const set<int>& line) {
        int first = *line.begin();
        int second = *line.rbegin();
        
        double deltaX1 = points[first].x - points[second].x;
        double deltaY1 = points[first].y - points[second].y;

        double deltaX2 = points[first].x - points[j].x;
        double deltaY2 = points[first].y - points[j].y;

        return (deltaX1 * deltaY2 == deltaY1 * deltaX2);
    }

    void distinctPoinsts(vector<Point>& points) {
        vector<Point> newPoints;
        for (auto itr = points.begin(); itr != points.end(); ++itr) {
            if (findPoint(newPoints, *itr) == newPoints.end()) {
                newPoints.push_back(*itr);
            }
        }

        points.swap(newPoints);
    }

    auto findPoint(vector<Point>& points, const Point& p) -> decltype(points.begin()) {
        for (auto itr = points.begin(); itr != points.end(); ++itr) {
            if (itr->x == p.x && itr->y == p.y)
                return itr;
        }
        return points.end();
    }


    //for test...
    void parsePoints(vector<Point>& points, const char* src) {
        const char* cur = src;
        bool firstNum = true;
        int  first = 0;
        int  second = 0;
        while (*cur != '\0') {
            if ('[' == *cur) {
                firstNum = true;
                ++cur;
            }
            else if (',' == *cur) {
                if (firstNum) {
                    firstNum = false;
                }
                else {
                    firstNum = true;
                }
                ++cur;
            }
            else if (']' != *cur) {
                if (firstNum) {
                    first = parseNumber(cur);
                }
                else {
                    second = parseNumber(cur);
                    points.push_back(Point(first, second));
                }
            }
            else {
                ++cur;
            }
        }
    }

    int parseNumber(const char*& cur) {
        bool negative = false;
        if ('-' == *cur) {
            negative = true;
            ++cur;
        }
        
        int num = 0;
        while (isdigit(*cur)) {
            num *= 10;
            num += *cur - '0';
            ++cur;
        }

        if (negative)
            num = -num;

        return num;
    }

private:
    vector<set<int> > lines;
};
#endif /*__leetcode_algorithm_149_h_*/