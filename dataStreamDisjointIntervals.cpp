
/*
Leetcode: data stream as disjoint intervals
https://leetcode.com/problems/data-stream-as-disjoint-intervals/
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
class SummaryRanges {
public:
    vector<Interval> num;
    /** Initialize your data structure here. */
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
        auto cmp = [](Interval a, Interval b) {
            return a.start < b.start;
        };
        auto inter = lower_bound(num.begin(), num.end(), Interval(val, val), cmp);
        if(inter!=num.begin() && (inter-1)->end >= val-1) {
            inter--;
        }
        int start = val, end = val;
        while(inter!=num.end() && inter->start <= val+1 && inter->end >= val-1) {
            start = min(start, inter->start);
            end = max(end, inter->end);
            inter = num.erase(inter);
        }
        num.insert(inter, Interval(start, end));
        
    }
    
    
    vector<Interval> getIntervals() {
        return num;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */