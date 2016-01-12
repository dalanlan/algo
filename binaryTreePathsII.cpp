// 257. Binary Tree Paths
// 480. LintCode
/* 
Given a binary tree, return all root-to-leaf paths.
*/

void dfs(vector<string>& res, string path, TreeNode* root) {
	if(path.empty()) {
		path += to_string(root->val);
	}
	else {
		path += "->" + to_string(root->val);
	}
    if(root->left == NULL && root->right == NULL) {
        res.push_back(path);
    }
	if(root->left != NULL) 
		dfs(res, path, root->left);
	if(root->right != NULL)
		dfs(res, path, root->right);
	
}
vector<string> binaryTreePaths(TreeNode* root) {
	vector<string> res;
	if(root == NULL) {
		return res;
	}
	string path;
	dfs(res, path, root);
	return res;
}