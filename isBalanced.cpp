

//Balanced Binary Tree

int depthOfTree(TreeNode *root)
{
	int depth = 0;
	if (root == NULL)
		return depth;
	if(root->left == NULL && root->right == NULL)
		return ++depth;
    return (max(depthOfTree(root->left),depthOfTree(root->right)) + 1);
	
}
bool isBalanced(TreeNode* root)
{
	if(root == NULL)
		return true;
	if(!isBalanced(root->left) || !isBalanced(root->right))
	    return false;

	return (abs(depthOfTree(root->left)-depthOfTree(root->right)) <= 1);
		
}