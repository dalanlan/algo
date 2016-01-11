// 110. Balanced Binary Tree

/*
Given a binary tree, determine if it is height-balanced.
For this problem, a height-balanced binary tree is defined
as a binary tree in which the depth of the two subtrees of
every node never differ by more than 1
*/

int helper(TreeNode* root) {
	if(root->left == NULL && root->right == NULL) {
		return 1;
	}
	int lf = helper(root->left);
	int rt = helper(root->right);
	if(lf == -1 || rt == -1 || abs(lf-rt)>1 ) {
		return -1;
	}
	else return max(lf, rt)+1;
}
bool isBalanced(TreeNode* root) {
	if(helper(root) != -1) {
		return true;
	}
	else {
		return false;
	}
}