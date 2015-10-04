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