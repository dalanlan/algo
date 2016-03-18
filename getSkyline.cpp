
/*
LeetCode: the skyline problem
https://leetcode.com/problems/the-skyline-problem/
*/


/*
The basic idea:
https://leetcode.com/discuss/67091/once-for-all-explanation-with-clean-java-code-nlog-time-space

for position in sorted(all start points and all end points)
       if this position is a start point
              add its height
       else if this position is a end point
              delete its height
       compare current max height with previous max height, if different, add current position together with this new max height to our result, at the same time, update previous max height to current max height;

*/
class Solution {
public:
    vector<pair<int,int>> getSkyline(vector<vector<int>>& buildings) {
	vector<pair<int,int>> res;
	vector<pair<int,int>> heights;

	for(auto v:buildings) {
		heights.push_back(make_pair(v[0], -v[2]));
		heights.push_back(make_pair(v[1], v[2]));
	}
	// why do we need sort?
	// cause we want to tie endpoints together
    sort(heights.begin(), heights.end());
	// max-heap
	// priority_queue in c++ doesnt support erase operation
	// priority_queue<int, vector<pair<int,int>>> pq;
	
	// act like a min-heap
	multiset<int> set;
	set.insert(0);
	int prev = 0;

	for(auto h:heights) {
		if(h.second < 0) {
			set.insert(-h.second);
		}
		else {
			set.erase(set.find(h.second));
		}
		// the max value is put in the end 
		int cur = *set.rbegin();
		if(prev != cur) {
			res.push_back(make_pair(h.first, cur));
			prev = cur;
		}
	}
	return res; 
}
};