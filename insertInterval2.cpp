
/*
Leetcode: insert interval
https://leetcode.com/problems/insert-interval/
*/


/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        int i=0;
        while(i<intervals.size() && newInterval.start > intervals[i].end) {
            i++;
        }
        while(i<intervals.size() && newInterval.end >= intervals[i].start) {
            newInterval.start = min(newInterval.start, intervals[i].start);
            newInterval.end = max(newInterval.end, intervals[i].end);
            intervals.erase(intervals.begin()+i);
        } 
        intervals.insert(intervals.begin()+i, newInterval);
        return intervals;
    }
};