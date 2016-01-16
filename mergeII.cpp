/*

LintCode 156: merge interval 

-----------------------------
example:
[                     [
  [1, 3],               [1, 6],
  [2, 6],      =>       [8, 10],
  [8, 10],              [15, 18]
  [15, 18]            ]
]

*/
/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 */


/**
 * @param intervals: interval list.
 * @return: A new interval list.
 */
// input reference 
// const 
// bool static 
bool static compare(const Interval &a, const Interval &b) {
	return a.start < b.start;
}
vector<Interval> merge(vector<Interval> &intervals) {
    vector<Interval> res;
    if(intervals.size() == 0) {
    	return res;
    }
    
    sort(intervals.begin(), intervals.end(), compare);

    int start=intervals[0].start, end = intervals[0].end;
    
    for(int i=1; i<intervals.size(); i++) {
    	if(intervals[i].start > end) {
    		res.push_back(Interval(start, end));
    		start = intervals[i].start;
    		end = intervals[i].end;
    	}
    	else if(intervals[i].end > end) {
    		end = intervals[i].end;
    	}

    }
    res.push_back(Interval(start, end));
    return res;
}