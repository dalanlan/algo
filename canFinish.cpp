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

		for(auto& it: myMap) {
			it.second.erase(head);
			if(it.second.size() == 0) {
				Q.push(it.first);
			}
		}

		// for(int i=0; i<numCourses;i++) {
		// 	if(myMap.find(i) == myMap.end()) {
		// 		Q.push(i);
		// 	}
		// }
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

bool canFinish(int numCourses, vector<pair<int, int> >& prerequisites) {
	unordered_map<int, unordered_set<int>> myMap;

	//in-degree
	int *degree = new int[numCourses];
	for(int i=0; i<numCourses; i++) {
		degree[i] = 0;
	}
	for(int i=0; i<prerequisites.size(); i++) {
		//for each element [a,b], we have myMap[a] = b, ...
		if(myMap[prerequisites[i].second].find(prerequisites[i].first) == myMap[prerequisites[i].second].end()) {
		myMap[prerequisites[i].second].insert(prerequisites[i].first);
		degree[prerequisites[i].first]++;
		}
	}

	queue<int> Q;

	for(int i=0; i<numCourses;i++) {
		if(degree[i] == 0) {
			Q.push(i);
		}
	}

	while(!Q.empty()) {
		int head = Q.front();
		Q.pop();

		if(myMap.find(head) != myMap.end()) {
			for(auto i= myMap[head].begin(); i != myMap[head].end();i++) {
				degree[*i]--;
				if(degree[*i] == 0){
					Q.push(*i);
				}
			}
		}
	}

	int count = 0;
	for(int i=0; i<numCourses;i++) {
		count+= degree[i];
	}
	return count==0;

}