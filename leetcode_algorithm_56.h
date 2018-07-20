/*
Given a collection of intervals, merge all overlapping intervals.
Example 1:
  Input: [[1,3],[2,6],[8,10],[15,18]]
  Output: [[1,6],[8,10],[15,18]]
Example 2:
  Input: [[1,4],[4,5]]
  Output: [[1,5]]
*/
#ifndef _leetcode_algorithm_56_h_
#define _leetcode_algorithm_56_h_
#include "basic_headers.h"

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        bool changed = false;
        auto cnt = intervals.size();
        do {
            changed = false;
            for (int i = 0; i < cnt; ++i) {
                for (int j = i + 1; j < cnt; ++j) {
                    if (overlap(intervals[i], intervals[j])) {
                        merge(intervals[i], intervals[j]);
                        swap(intervals[j], intervals[cnt - 1]);
                        --cnt;
                        changed = true;
                    }
                }
            }
        } while (changed);

        return vector<Interval>(intervals.begin(), intervals.begin() + cnt);
    }

    bool overlap(const Interval &a, const Interval &b) const {
        return !(a.end < b.start || b.end < a.start);
    }

    bool merge(Interval &a, const Interval& b) const {
        if (!overlap(a, b))
            return false;

        a.start = a.start < b.start ? a.start : b.start;
        a.end = a.end < b.end ? b.end : a.end;
        return true;
    }

    void swap(Interval &a, Interval &b) const {
        int tmp = a.start;
        a.start = b.start;
        b.start = tmp;

        tmp = a.end;
        a.end = b.end;
        b.end = tmp;
    }
};
#endif /*_leetcode_algorithm_56_h_*/
