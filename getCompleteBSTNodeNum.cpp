
int getHeight(TreeNode* root) {
	if(!root) {
		return 0;
	}
	return 1+getHeight(root->left);
}

int calculateNode(TreeNode *root) {
	if(!root) {
		return 0;
	}
	int leftHeight = getHeight(root->left);
	int rightHeight = getHeight(root->right);

	// left is full
	if(leftHeight == rightHeight) {
		return pow(2, leftHeight) + calculateNode(root->right);
	}
	else {
		return pow(2, rightHeight) + calculateNode(root->left);
	}
}
int calculateNode(TreeNode* root) {
	int res = 0;
	int height = getHeight(root);
	res = 2^height-1;

	TreeNode *cur = root;
	while(cur) {
		if(!cur->left && !cur->right) {
			break;
		}
		if(getHeight(cur->left) == getHeight(cur->right)) {
			cur = cur->right;
		}
		else {
			cur = cur->left;
		}
	}

}

