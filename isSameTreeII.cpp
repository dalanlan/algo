// Same Tree
// Given two binaries, write a function to check
// if they are equal or not.

bool isSameTree(TreeNode* p, TreeNode* q) {
	if(p == NULL && q != NULL) {
		return false;
	}
	if(q == NULL && p != NULL) {
		return false;
	}

	if(p!= NULL && q!=NULL) {
		if(p->val != q->val) {
			return false;
		}
		if (!isSameTree(p->left, q->left) || !isSameTree(p->right, q->right)) {
			return false;
		}
	}
	return true;	
}