
/*
LintCode : Determine if a given graph is a valid tree
http://www.lintcode.com/zh-cn/problem/graph-valid-tree/
*/


// WA: Could have cycle & not connected sub graph
class Solution {
public:
    /**
     * @param n an integer
     * @param edges a list of undirected edges
     * @return true if it's a valid tree, or false
     */
    bool validTree(int n, vector<vector<int>>& edges) {
        int sz = edges.size();
        if(sz != n-1) {
        	return false;
        }
        unordered_map<int, int> myMap;
        for(int i=0; i<sz; i++) {
        	myMap[i] = 0;
        }
        for(int i=0; i<sz; i++) {
        	myMap[edges[i][0]]++;
        	myMap[edges[i][1]]++;
        }
        for(int i=0; i<sz; i++) {
        	if(myMap[i] == 0) {
        		return false;
        	}
        }
        return true;
    }
};

// solution 1
// union find : quick find 
// Chech the cycle 

void unionSet(vector<int>& unionV, int a, int b) {
	int aVal = unionV[a];
	int bVal = unionV[b];
	int res = min(aVal, bVal);
	for(int i=0; i< unionV.size(); i++) {
		if(unionV[i] == aVal || unionV[i] == bVal) {
			unionV[i] = res;
		}
	}
}
bool validTree(int n, vector<vector<int>>& edges) {
	int sz = edges.size();
	if(sz != n-1) {
		return false;
	}
	vector<int> unionV(n, 0);
	// node: [0, n-1]
	// unionV[i] 
	// maintains the invariant that p and q are connected if and only if id[p] is equal to id[q]. 
	// In other words, all sites in a component must have the same value in id[].
	for(int i=0; i<n; i++) {
		unionV[i] = i;
	}
	for(int i=0; i<sz; i++) {
		// check check
	    if(unionV[edges[i][0]] == unionV[edges[i][1]]) {
	        return false;
	    }
		unionSet(unionV, edges[i][0], edges[i][1]);
	}
	for(int i=0; i<n; i++) {
		if(unionV[i] != 0) {
			return false;
		}
	} 
	return true;

}

// solution 2
// quick union 
bool validTree(int n, vector<vector<int>>& edges) {
	int sz = edges.size();
	if(sz != n-1) {
		return false;
	}

	//unionV[i]: 
	vector<int> unionV(n, 0);
	for(int i=0; i<n; i++) {
		unionV[i] = i;
	}
	for(int i=0; i<sz; i++) {
		if(find(edges[i][0], unionV) == find(edges[i][1], unionV)) {
			return false;
		}
		unionF(edges[i][0], edges[i][1], unionV);
	}
	return true;

}

void unionF(int a, int b, vector<int> &unionV) {
	unionV[find(b, unionV)]=find(a, unionV);
}

int find(int edge, vector<int> &unionV) {
	if(unionV[edge] == edge) {
		return edge;
	}
	return find(unionV[edge], unionV);
}