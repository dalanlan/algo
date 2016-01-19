
/*
LintCode 68: post order traversal of binary tree
*/


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
     * @return: Postorder in vector which contains node values.
     */
public:
    vector<int> postorderTraversal(TreeNode *root) {
    	stack<TreeNode*> s;
    	TreeNode* tmp = root;
    	vector<int> res;
    	while(tmp != NULL || !s.empty()) {
    		if(tmp != NULL) {
    			s.push(tmp);
    			res.insert(res.begin(), tmp->val);
    			tmp = tmp->right;
    		}
    		else {
    			tmp = s.top();
    			s.pop();
    			tmp = tmp->left;
    		}
    	}
    	return res;
    }
};