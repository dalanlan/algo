
/*
LintCode 67: Inorder traversal of binary tree
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
     * @return: Inorder in vector which contains node values.
     */
public:
vector<int> inorderTraversal(TreeNode* root) {
	stack<TreeNode*> s;
	TreeNode* tmp = root;
	vector<int> res;

	while(tmp != NULL || !s.empty()) {
		if(tmp != NULL) {
			s.push(tmp);
			tmp = tmp->left;
		}
		else {
			tmp = s.top();
			s.pop();
			res.push_back(tmp->val);
			tmp = tmp->right;
		}
	}
	return res;
}