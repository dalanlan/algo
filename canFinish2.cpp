
/*
Leetcode: course schedule
https://leetcode.com/problems/course-schedule/
*/
bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
	unordered_map<int, unordered_set<int>> map;

	vector<int> degree(numCourses, 0);

	for(int i=0; i<prerequisites.size(); i++) {
		// pair<int,int>
		int orig = prerequisites[i].first;
		int depe = prerequisites[i].second;
		if(map[depe].count(orig) == 0) {
		    map[depe].insert(orig);
		    degree[orig]++;
		}
	}

	queue<int> q;

	for(int i=0; i<degree.size(); i++) {
		if(degree[i] == 0) {
			q.push(i);
		}
	}

	while(!q.empty()) {
		int tmp = q.front();
		q.pop();

		if(map.count(tmp)) {
		  // This works
		  //for(auto iter = map[tmp].begin(); iter != map[tmp].end(); iter++) {
		  //    degree[*iter]--;
		  //    if(degree[*iter] == 0) {
		  //        q.push(*iter);
		  //    }
		  //}
		  // This works as well 
		  for(auto iter:map[tmp]) {
		      degree[iter]--;
		      if(degree[iter] == 0) {
		          q.push(iter);
		      }
		  }
		}
	}
	for(int d:degree) {
		if(d != 0) {
			return false;
		}
	}
	return true;
}