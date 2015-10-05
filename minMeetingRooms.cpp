bool static compare(const Interval &i, const Interval &j) {
  return i.start < j.start;
}

int minMeetingRooms(vector<Interval>& intervals) {
  int count = 0;
  if(intervals.size() == 0)
    return count;

  sort(intervals.begin(), intervals.end(), compare);

  priority_queue<int, vector<int>, greater<int>> q;
  q.push(intervals[0].end);
  count++;
  int end;
  for(int i=1;i<intervals.size();i++) {
    end = q.top();

    if(intervals[i].start < end) {
      count++;
      q.push(intervals[i].end);
    }
    else {
      q.pop();
      q.push(intervals[i].end);
    }
  }
  return count;

}