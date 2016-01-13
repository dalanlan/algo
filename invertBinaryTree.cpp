/*
LintCode 175: reverse a binary tree

  1         1
 / \       / \
2   3  => 3   2
   /       \
  4         4

*/

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */


// solution 1: recursive solution
void invertBinaryTree(TreeNode *root) {
	if(root->left != NULL) {
		invertBinaryTree(root->left);
	}
	if(root->right != NULL) {
		invertBinaryTree(root->right);
	}
	if(root != NULL) {
		TreeNode* tmp = root->left;
		root->left = root->right;
		root->right = tmp;
	}
}

// solution 2: iterative solution
// use a queue
void invertBinaryTree(TreeNode *root) {
	queue<TreeNode*> q;

	TreeNode *cur, *tmp;

	q.push(root);
	while(!q.empty()) {
		cur = q.front();
		q.pop();
		tmp = cur->left;
		cur->left = cur->right;
		cur->right = tmp;

		if(cur->left) {
			q.push(cur->left);
		}
		if(cur->right) {
			q.push(cur->right);
		}
	}
}