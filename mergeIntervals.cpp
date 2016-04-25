bool static compare(const Interval &i, const Interval &j) {
        return i.start < j.start;
}
vector<Interval> merge(vector<Interval>& intervals) {
    vector<Interval> res;
    if(intervals.size() == 0)
        return res;
        
    sort(intervals.begin(),intervals.end(),compare);
    
    Interval tmp = intervals[0];
    for(int i=1; i<intervals.size(); i++) {
        if (intervals[i].start > tmp.end ) {
            res.push_back(tmp);
            tmp = intervals[i];
        }
        else if (intervals[i].end > tmp.end) {
            tmp.end = intervals[i].end;
        }
    }
    res.push_back(tmp);
    return res;
   
}

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
    bool static compare(const Interval& i1, const Interval& i2) {
        return i1.start < i2.start;
    }
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> res;
        int sz = intervals.size();
        if(sz == 0) {
            return res;
        }
        sort(intervals.begin(), intervals.end(), compare);
        int start = intervals[0].start;
        int end = intervals[0].end;
        for(int i=1; i<sz; i++) {
            if(intervals[i].start <= end) {
                end = max(end, intervals[i].end);
            }
            else {
                res.push_back(Interval(start, end));
                start = intervals[i].start;
                end = intervals[i].end;
            }
        }
        res.push_back(Interval(start, end));
        return res;
    }
};