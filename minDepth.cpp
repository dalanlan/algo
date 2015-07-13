

//Minimum Depth of  Binary Tree

//BFS


bool isLeaf(TreeNode *root)
{
	return (root->left==NULL && root->right ==NULL);
}
    int minDepth(TreeNode* root) 
    {
        int depth = 0;
    	if(root == NULL)
        	return depth;

         if(isLeaf(root))
         	return ++depth;

          	else
         	{
         	    
         	    if(root->left != NULL && root->right == NULL)
         	        return (minDepth(root->left)+1);
         	    if(root->left == NULL && root->right != NULL)
         	        return (minDepth(root->right)+1);
         	    else
         	        return (min(minDepth(root->left),minDepth(root->right))+1);
         	}
    }
    // int minDepth(TreeNode* root) 
    // {

	// queue<TreeNode*> v;
	// v.push(root);

	// while(!v.empty())
	// {	
	// 	TreeNode* tmp = v.front();
	// 	if(isLeaf(tmp))
	// 		return depth+1;

	// 	else{
	// 		if(tmp->left !=NULL) v.push(tmp->left);
	// 		if(tmp->right != NULL) v.push(tmp->right);

	// 		depth++;
	// 		v.pop();
	// 	}
	// }
	
   