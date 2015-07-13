
//Path Sum
/*
Determine if the tree has a root-to-leaf path 
such that adding up all the values along the path 
equals the given sum.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool isLeaf(TreeNode *root)
{
	return (root->left == NULL && root->right == NULL);
}
bool hasPathSum(TreeNode* root, int sum) 
{
	//DP
	if(root==NULL)
		return false;
	
	
	if(isLeaf(root))
		return (root->val == sum);

	return ( hasPathSum(root->left, sum-root->val) || hasPathSum(root->right,sum-root->val));


}