// Binary Tree Level Order Traversal II

/*
Given a binary tree, return the bottom-up 
level order traversal of its nodes' values. 
(ie, from left to right, level by level from leaf to root).
*/

vector<vector<int>> levelOrderBottom(TreeNode* root) {
	vector<vector<int>> res;

	levelOrderBottom(root, res);

	return res;
}

void levelOrderBottom(TreeNode* root, vector<vector<int>>& res) {
	if(root->left != NULL && root->right != NULL) {
		res.push_back(vector<TreeNode*>(root->left, root->right));
	}
	else if(root->left != NULL) {
		res.push_back(vector<TreeNode*>(root->left));
	} else if(root->right != NULL) {
		res.push_back(vector<TreeNode*>(root->right));
	}
	res.push_back(vector<TreeNode*>(root));

}