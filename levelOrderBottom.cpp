// Binary Tree Level Order Traversal II

/*
Given a binary tree, return the bottom-up 
level order traversal of its nodes' values. 
(ie, from left to right, level by level from leaf to root).
*/

vector<vector<int>> levelOrderBottom(TreeNode* root) {
	vector<vector<int>> res;

	if(root == NULL) {
		return res;
	}

	queue<TreeNode*> Q;
	Q.push(root);

	TreeNode* t;
	vector<int> path;
	int sz;

	while(!Q.empty()) {
		path.clear();
		sz = Q.size();
		for(int i=0; i<sz; i++) {
			t = Q.front();
			Q.pop();
			path.push_back(t->val);
			if(t->left != NULL) {
				Q.push(t->left);
			}
			if(t->right != NULL) {
				Q.push(t->right);
			}
		}
		res.push_back(path);
	}

	for(int i=0;i<res.size()/2;i++) {
		swap(res[i], res[res.size()-i-1]);
	}
	return res;
}

