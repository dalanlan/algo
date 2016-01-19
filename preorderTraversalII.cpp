
/*
LintCode 66: Preorder traversal of binary tree
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

 vector<int> preorderTraversal(TreeNode *root) {
 	stack<TreeNode*> s;
 	vector<int> res;
 	TreeNode *tmp = root;

 	while(tmp != NULL || s.empty()) {
 		if(tmp != NULL) {
 			s.push(tmp);
 			res.push_back(tmp->val);
 			tmp = tmp->left;
 		}
 		else {
 			tmp = s.top();
 			s.pop();
 			tmp = tmp->right;
 		}
 	}
 	return res;
 }