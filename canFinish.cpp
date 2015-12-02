// Course schedule

// Topological sort
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <utility>  
using namespace std;


bool canFinish(int numCourses, vector<pair<int, int> >& prerequisites) {
	
	unordered_map<int, unordered_set<int> > myMap;
	

	for(int i = 0; i < prerequisites.size(); i++) {
		//for each element [a,b], we have myMap[a] = b, ...
		myMap[prerequisites[i].first].insert(prerequisites[i].second);

	}
	
	queue<int> Q;

	for(int i=0; i<numCourses; i++) {
		if(myMap.find(i) == myMap.end()) {
			Q.push(i);
		}
	}
	while(!Q.empty()) {
		int head = Q.front();
		Q.pop();
		// for(int i=0; i<myMap.size(); i++) {
		// 	myMap[i].erase(head);
		// }
		for(auto it = myMap.begin(); it != myMap.end(); it++) {
			*it.erase(head);
		}

		for(int i=0; i<numCourses;i++) {
			if(myMap.find(i) == myMap.end()) {
				Q.push(i);
			}
			else if(myMap[i].size() == 0) {
				Q.push(i);
			}
		}
	}
	
	if(myMap.empty()) {
		return true;
	}
	else {
		return false;
	}

}

int main() {
	vector<pair<int, int> > prerequisites;
	prerequisites.push_back(make_pair(1,0));
	cout<<canFinish(2, prerequisites)<<endl;
	return 0;
}