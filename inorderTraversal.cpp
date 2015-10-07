// Solution 1: recursive
void dfs(TreeNode* root, vector<int> &res) {
	if(root == NULL)
		return;
	dfs(root->left, res);
	res.push_back(root->val);
	dfs(root->right,res);
}
vector<int> inorderTraversal(TreeNode* root) {
	vector<int> res;
	dfs(root, res);
	return res;
}


// Solution 2: iterative
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
    if(root == NULL)
    	return res;
    	
    stack<TreeNode*> stk;
    TreeNode* tmp = root;
    
   	while(!stk.empty() || tmp != NULL) {
   		if(tmp != NULL) {
   			stk.push(tmp);
   			tmp = tmp->left;
   		}
   		else {
   			tmp = stk.top();
   			res.push_back(tmp->val);
   			stk.pop();
   			tmp = tmp->right;
   		}
   	}
   	return res;
}