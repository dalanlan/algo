// Minimum height trees

/*
For a undirected graph with tree characteristics,
we can choose any nodes as the root. The result graph
is then a rooted tree. Among all possible rooted trees,
those with min height are called min height are called
min height tree(MHTs). Given such a graph, write a 
function to find all the MHTs and return a list of their
root labels.
*/
vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
	vector<int> res;
	if(n == 0) {
		return res;
	}
	if(n == 1) {
		res.push_back(0);
		return res;
	}

	unordered_map<int, unordered_set<int>> myMap;
	for(int i=0; i<edges.size(); i++) {
		myMap[edges[i].first].insert(edges[i].second);
		myMap[edges[i].second].insert(edges[i].first);
	}

	vector<int> leaves;
	for(int i=0; i<myMap.size(); i++) {
		if(myMap[i].size() == 1) {
			leaves.push_back(i);
		}
	}
	int j;
	while(n > 2) {
		n -= leaves.size();
		vector<int> newLeaves;
		for(int i=0; i< leaves.size(); i++){
			j = *(myMap[leaves[i]].begin());
			myMap[j].erase(leaves[i]);
			if(myMap[j].size() == 1) {
				newLeaves.push_back(j);
				
			}
		}
		leaves = newLeaves;

	}
	return leaves;

	}