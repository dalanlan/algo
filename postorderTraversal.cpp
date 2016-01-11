// 145. Binary Tree Postorder Traversal

/*
Given a binary tree, return the postorder traversal
of its order's values.
*/


// solutiion 1: recursive

void dfs(vector<int>& res, TreeNode* root) {
	if(root->left != NULL) {
		dfs(res, root->left);
	}
	if(root->right != NULL) {
		dfs(res, root->right);
	}
	res.push_back(root->val);
}
vector<int> postorderTraversal(TreeNode* root) {
	vector<int> res;

	if(root == NULL) {
		return res;
	}
	dfs(res, root);

	return res;
}

// solution 2: iterative
// Use a stack
vector<int> postorderTraversal(TreeNode* root) {
	stack<TreeNode*> stk;
	vector<int> res;
	TreeNode* tmp = root;

	while(!stk.empty() || tmp != NULL) {
		if(tmp != NULL) {
			stk.push(tmp);
			res.insert(res.begin(), tmp->val);
			tmp = tmp->right;
		}
		else {
			tmp = stk.top();
			stk.pop();
			tmp = tmp->left;
		}
	}
	return res;
}
