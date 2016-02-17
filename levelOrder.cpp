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



//solution 2: dfs

vector<vector<int>> levelOrder(TreeNode *root) {
	vector<vector<int>> res;
	if(root == NULL) {
		return res;
	}

	int maxLevel = 0;
	while(true) {
		vector<int> level;
		dfs(root, 0, level, maxLevel);
		if(level.size() == 0) {
			break;
		}
		res.push_back(level);
		maxLevel++;
	}
	return res;
}
void dfs(TreeNode* root, int depth, vector<int> &level, int maxLevel) {
	if(depth > maxLevel || root == NULL) {
		return;
	}

	if(depth == maxLevel) {
		level.push_back(root->val);
	}
	dfs(root->left, depth+1, level, maxLevel);
	dfs(root->right, depth+1, level, maxLevel);
}