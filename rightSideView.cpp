vector<int> rightSideView(TreeNode* root) {
    
    //BFS should work

    vector<int> res;
    if(root==NULL)
    	return res;

    queue<TreeNode*> ans;

    ans.push(root);
    while(!ans.empty())
    {
    	int size=ans.size();
    	for(int i=0;i<size;i++)
    	{
    		TreeNode *top = ans.front();
    		ans.pop();
    		if(i==0)
    			res.push_back(top->val);
    		if(top->right)
    			ans.push(top->right);
    		if(top->left)
    			ans.push(top->left);
    	}

    }
    return res;

}