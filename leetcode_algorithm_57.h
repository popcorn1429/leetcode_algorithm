/*
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
You may assume that the intervals were initially sorted according to their start times.
Example 1:
    Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
    Output: [[1,5],[6,9]]
Example 2:
    Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
    Output: [[1,2],[3,10],[12,16]]
    Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
*/
#ifndef _leetcode_algorithm_57_h_
#define _leetcode_algorithm_57_h_
#include "basic_headers.h"

#ifndef min
#define min(a,b) (((a) < (b)) ? (a) : (b))
#endif
#ifndef max
#define max(a,b) (((a) < (b)) ? (b) : (a))
#endif

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> result;
        bool inserted = false;
        for (const Interval &interval : intervals) {
            // interval << newInterval
            if (interval.end < newInterval.start) {
                result.push_back(interval);
                continue;
            }
                
            // interval X newInterval
            if (overlap(interval, newInterval)) {
                if (!inserted) {
                    result.push_back(Interval(min(interval.start, newInterval.start), max(interval.end, newInterval.end)));
                    inserted = true;
                }
                else {
                    result.back().end = max(interval.end, newInterval.end);
                }
                continue;
            }

            // interval >> newInterval
            if (newInterval.end < interval.start) {
                if (!inserted) {
                    result.push_back(newInterval);
                    inserted = true;
                }
                result.push_back(interval);
            }
        }

        if (!inserted) {
            result.push_back(newInterval);
        }
        return result;
    }


    bool overlap(const Interval &a, const Interval &b) const {
        return !(a.end < b.start || b.end < a.start);
    }
};



#endif /*_leetcode_algorithm_57_h_*/