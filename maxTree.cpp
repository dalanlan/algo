
/*
Came from nowhere: max tree

Given an integer array with no duplicates. A max tree building on this array is defined as follow:
The root is the maximum number in the array The left subtree and right subtree are the max trees of the subarray divided by the root number. Construct the max tree by the given array.
Example Given [2, 5, 6, 0, 3, 1], the max tree constructed by this array is:
    6
   / \
  5   3
 /   / \
2   0   1

Challenge O(n) time and memory.

*/

class TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int v) {
		val = v;
		left = right = NULL;
	}
};

// solution 1: recursive
// top-down
TreeNode* maxTree(vector<int> &A) {
	if(A.size() == 0) {
		return NULL;
	}
	return maxTreeNode(A, 0, A.size()-1);
}

TreeNode* maxTree(vector<int> &A, int lo, int hi) {
	if(lo > hi) {
		return NULL;
	}
	if(lo == hi) {
		return new TreeNode(lo);
	}

	int maxNode = INT_MIN;
	int maxInd = -1;
	for(int i=lo; i<=hi; i++) {
		if(maxNode < A[i]) {
			maxNode = A[i];
			maxInd = i;
		}
	}

	TreeNode* root = new TreeNode(maxNode);
	root->left = maxTree(A, lo, maxInd-1);
	root->right = maxTree(A, maxInd+1. hi);
	return root;
}

// solution 2: bottom-up

TreeNode* maxTree(vector<int> &A) {
	if(A.size() == 0) {
		return NULL;
	}

	stack<TreeNode*> stk;
	for(int i=0; i<A.size(); i++) {
		TreeNode* node = new TreeNode(A[i]);
		while(!stk.empty() && nums[i] > stk.top()->val) {
			node->left = stk.top();
			stk.pop();
		}
		if(!stk.empty()) {
			stk.top()->right = node;
		}
		stk.push(node);
	}
	
	while(stk.size() > 1) {
		stk.pop();
	}
	return stk.top();

}