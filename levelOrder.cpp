// Binary Tree Level Order Traversal

/*
Given a binary tree, return the level order traversal 
of its nodes' values. (ie, from left to right, level by level).
*/

vector<vector<int>> levelOrder(TreeNode* root) {
	vector<vector<int>> res;

	if(root == NULL) {
		return res;
	}

	queue<TreeNode*> Q;

	Q.push(root);

	int size;
	vector<int> tmp;
	TreeNode* t;
	while(!Q.empty()) {
		tmp.clear();
		size = Q.size();
		for(int i=0; i<size; i++) {
			t = Q.front();
			Q.pop();
			tmp.push_back(t->val);
			if(t->left != NULL) Q.push(t->left);
			if(t->right != NULL) Q.push(t->right);
		}
		res.push_back(tmp);
	}
	return res;
}

