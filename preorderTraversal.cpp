// 144. Binary Tree Preorder Traversal
// root, root->left, root->right


/*
Given a binary tree, return the preorder traversal
of its nodes' values.

Ref:
https://leetcode.com/discuss/71943/preorder-inorder-and-postorder-iteratively-summarization

*/


vector<int> preorderTraversal(TreeNode* root) {
	stack<TreeNode*> stk;
	vector<int> res;
	TreeNode* tmp = root;

	while(tmp != NULL || !stk.empty()) {
		if(tmp != NULL) {
			stk.push(tmp);
			res.push_back(tmp->val);
			tmp = tmp->left;
		}
		else {
			tmp = stk.top();
			stk.pop();
			tmp = tmp->right;
		}
	}
}