
/*
LintCode: Complete binary tree
*/


class TreeNode {
	public:
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int v) {
		val = v;
		left = right = NULL;
	}
};



bool isComplete(TreeNode* root) {
	if(root == NULL) {
		return true;
	}

	queue<TreeNode*> q;
	q.push(root);

	bool flag = false;

	while(!q.empty()) {
		TreeNode* tmp = q.front();
		q.pop();

		if(!tmp->left && tmp->right) {
			return false;
		}
		if(flag && (tmp->left || tmp->right)) {
			return false;
		}
		if(!tmp->left || !tmp->right) {
			flag = true;
		}
		if(tmp->left) {
			q.push(tmp->left);
		}
		if(tmp->right) {
			q.push(tmp->right);
		}
	}
	return true;

}