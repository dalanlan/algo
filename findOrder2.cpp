/*
LeetCode: course schedule ii

https://leetcode.com/problems/course-schedule-ii/

*/

vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
	unordered_map<int, unordered_set<int>> map;
	vector<int> degree(numCourses, 0);

	for(int i=0; i<prerequisites.size(); i++) {
		int orig = prerequisites[i].first;
		int depe = prerequisites[i].second;

		if(map[depe].count(orig) == 0) {
			map[depe].insert(orig);
			degree[orig]++;
		}
	}

	queue<int> q;
	vector<int> ans; 
	for(int i=0; i<numCourses; i++) {
		if(degree[i] == 0) {
			q.push(i);
			ans.push_back(i);
		}
	}	

	while(!q.empty()) {
		int tmp = q.front();
		q.pop();

		if(map.count(tmp)) {
			for(auto s: map[tmp]) {
				degree[s]--;
				if(degree[s] == 0) {
					q.push(s);
					ans.push_back(s);
				}

			}
		}
	}

	for(int d:degree) {
		if(d != 0) {
			return {};
		}
	}
	return ans;
}