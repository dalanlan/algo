// Course Schedule II

/*
There are a total of n courses you have to take,
labeled from 0 to n-1.
Given the total number of courses and a list of 
prerequisite pairs, return the ordering of courses
you should take to finish all courses.
*/

vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
	
	unordered_map<int, unordered_set<int>> myMap;
	int *degree = new int [numCourses];
	for(int i=0;i<numCourses;i++) {
		degree[i] = 0;
	}

	for(int i=0; i<prerequisites.size();i++) {
		if(myMap[prerequisites[i].second].find(prerequisites[i].first) == myMap[prerequisites[i].second].end()) {
			myMap[prerequisites[i].second].insert(prerequisites[i].first);
			degree[prerequisites[i].first]++;
		}
	}

	queue<int> Q;
	for(int i=0; i<numCourses; i++) {
		if(degree[i] == 0) {
			Q.push(i);
		}
	}

	int head;
	vector<int> ans;
	while(!Q.empty()) {
		head = Q.front();
		ans.push_back(head);
		Q.pop();

		if(myMap.find(head) != myMap.end()) {
			for(auto &l: myMap[head]) {	
				degree[l]--;
				if(degree[l] == 0) {
					Q.push(l);
				}
			}
		}
	}
	if(ans.size() == numCourses) {
		return ans;
	}
	else {
		return vector<int>();
	}

}