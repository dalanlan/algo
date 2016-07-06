
/*
LeetCode: clone graph
https://leetcode.com/problems/clone-graph/
*/


/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */

 // dfs 
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> map;
        // dfs 
        dfs(node, map);
        return map[node];
        
    }
    void dfs(UndirectedGraphNode *node, unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> &map) {
        
        if(!node || map.count(node)) {
            return;
        }
        
        UndirectedGraphNode *newNode = new UndirectedGraphNode(node->label);
        map[node] = newNode;
        
        for(int i=0; i<node->neighbors.size(); i++) {
            dfs(node->neighbors[i], map);
            newNode->neighbors.push_back(map[node->neighbors[i]]);
        }
    }
};


// bfs



UndirectedGraphNode *cloneGraph(UndirectedGraphNode* node) {
	if(!node) {
		return NULL;
	}
	unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> map;
	queue<UndirectedGraphNode*> q;
	
	UndirectedGraphNode* newNode = new UndirectedGraphNode(node->label);
	map[node] = newNode;
	q.push(node);

	while(!q.empty()) {
		// original node
		UndirectedGraphNode* tmp  = q.front();
		q.pop();

		for(int i=0; i<tmp->neighbors.size(); i++) {
			if(!map.count(tmp->neighbors[i])) {
			
			UndirectedGraphNode* n = new UndirectedGraphNode(tmp->neighbors[i]->label);
			map[tmp->neighbors[i]] = n;
			q.push(tmp->neighbors[i]);
			}
			
            map[tmp]->neighbors.push_back(map[tmp->neighbors[i]]);
			
		}
	}
	return newNode;
}