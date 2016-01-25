

/*
LintCode : Topological sorting
http://www.lintcode.com/zh-cn/problem/topological-sorting/
*/

/**
 * Definition for Directed graph.
 * struct DirectedGraphNode {
 *     int label;
 *     vector<DirectedGraphNode *> neighbors;
 *     DirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    /**
     * @param graph: A list of Directed graph node
     * @return: Any topological order for the given graph.
     */
    vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*> graph) {
        // in-degree 
        unordered_map<DirectedGraphNode*, int> myMap;
        for(int i=0; i<graph.size();i++) {
        	for(int j=0; j<graph[i]->neighbors.size(); j++) {
        		if(myMap.find(graph[i]->neighbors[j]) == myMap.end()) {
        			myMap[graph[i]->neighbors[j]]=1;
        		}
        		else {
        			myMap[graph[i]->neighbors[j]]++;
        		}
        	}
        }

        queue<DirectedGraphNode*> q;
        for(int i=0; i<graph.size(); i++) {
        	if(myMap.find(graph[i]) == myMap.end()) {
        		q.push(graph[i]);
        	}
        }

        vector<DirectedGraphNode*> res;
        DirectedGraphNode *tmp;
        while(!q.empty()) {
        	tmp = q.front();
        	q.pop();
        	res.push_back(tmp);
        	for(int i=0; i<tmp->neighbors.size(); i++) {
        		myMap[tmp->neighbors[i]]--;
        		if(myMap[tmp->neighbors[i]] == 0) {
        			q.push(tmp->neighbors[i]);
        		}
        	}
        }
        return res; 
    }
};

// DFS-like top sort
// ????


