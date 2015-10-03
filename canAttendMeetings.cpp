bool static compare(Interval i, Interval j) {
    return i.start < j.start;
} 
bool canAttendMeetings(vector<Interval>& intervals) {
    if(intervals.size() == 0)
        return true;
    sort(intervals.begin(), intervals.end(), compare);
    
    int start=intervals[0].start, end=intervals[0].end;
    for(int i=1;i<intervals.size();i++) {
        if(intervals[i].start < end)
            return false;
        start = intervals[i].start;
        end = intervals[i].end;
    }
    return true;
}