/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 */
class Solution {
public:
    /**
     * Insert newInterval into intervals.
     * @param intervals: Sorted interval list.
     * @param newInterval: new interval.
     * @return: A new interval list.
     */
     
     // extra storage space
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // write your code here
        
        vector<Interval> res;
        int i=0;
        while(i < intervals.size() && intervals[i].end < newInterval.start) {
            res.push_back(intervals[i++]);
        }
        while(i < intervals.size() && intervals[i].start <= newInterval.end) {
            // only base class 
            // not a pointer 
            newInterval = Interval(min(intervals[i].start, newInterval.start),
            max(intervals[i].end, newInterval.end));
            i++;
        }
        res.push_back(newInterval);
        while(i < intervals.size()) {
            res.push_back(intervals[i++]);
        }
        return res;
        
    }
};


// solution 2: in-place insert
     vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
         int ind = 0;
         while(ind < intervals.size() && intervals[ind].end < newInterval.start) {
             ind++;
         }
         while(ind < intervals.size() && intervals[ind].start <= newInterval.end) {
             newInterval = Interval(min(intervals[ind].start, newInterval.start),
             max(intervals[ind].end, newInterval.end));
            //  intervals[ind] = newInterval;
            intervals.erase(intervals.begin()+ind);
         }
         intervals.insert(intervals.begin()+ind, newInterval);
         return intervals;
     }