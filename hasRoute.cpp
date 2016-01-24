
/*
LeetCode : route between two nodes in graph
http://www.lintcode.com/zh-cn/problem/route-between-two-nodes-in-graph/ 
*/


// solution 1: BFS
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
     * @param s: the starting Directed graph node
     * @param t: the terminal Directed graph node
     * @return: a boolean value
     */
    bool hasRoute(vector<DirectedGraphNode*> graph,
                  DirectedGraphNode* s, DirectedGraphNode* t) {
        
        if(s == NULL || t==NULL) {
            return false;
        }
        
        queue<DirectedGraphNode*> q;
        q.push(s);
        
        while(!q.empty()) {
            DirectedGraphNode* tmp = q.front();
            if(tmp == t) {
                return true;
            }
            q.pop();
            for(int i=0; i<tmp->neighbors.size(); i++) {
                if(tmp->neighbors[i] == t) {
                    return true;
                }
                q.push(tmp->neighbors[i]);
            }
        }
        return false;
    }
};

// solution 2: DFS

bool hasRoute(vector<DirectedGraphNode*> graph,
                  DirectedGraphNode* s, DirectedGraphNode* t) {