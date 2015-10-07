
TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
	if(root == NULL)
		return NULL;

	stack<TreeNode*> stk;
	vector<TreeNode*> res;
	TreeNode* tmp = root;

	while(!stk.empty() || tmp != NULL) {
		if(tmp != NULL) {
			stk.push(tmp);
			tmp = tmp->left;
		} else {
			tmp = stk.top();
			res.push_back(tmp);
			stk.pop();
			tmp = tmp->right;
		}
	}
	
	for(int i=0;i<res.size()-1;i++) {
	    if(res[i] == p)
	    	return res[i+1];
	}		
	return NULL;
}