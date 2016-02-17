
/*
LintCode: binary tree level order traversal
http://www.lintcode.com/zh-cn/problem/binary-tree-level-order-traversal/
*/


// solution 1: use only a queue
/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
 
 
class Solution {
    /**
     * @param root: The root of binary tree.
     * @return: Level order a list of lists of integer
     */
public:
    vector<vector<int>> levelOrder(TreeNode *root) {


	vector<vector<int> > res;
	if(root==NULL) {
	    return res;
	}
	queue<TreeNode*> q;
	q.push(root);
	while(!q.empty()) {
		vector<int> path;
		int sz = q.size();
		for(int i=0; i<sz; i++) {
		
		TreeNode* tmp = q.front();
		path.push_back(tmp->val);
		q.pop();
		if(tmp->left) {
			q.push(tmp->left);
		}
		if(tmp->right) {
			q.push(tmp->right);
		}
		}	
		res.push_back(path);
	}
	return res;
}
};

// solution 2: adopt dfs 