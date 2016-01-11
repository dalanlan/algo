// 173. Binary Search Tree Iterator

/*
Implement an iterator over a binary search tree (BST).
Your iterator will be initialized with the root node
of a BST.
Calling next() will return the next smallest number 
in the BST.
*/


// solution 1: recusive way
vector<int> tree;
int cur=0;

void dfs(TreeNode* root, vector<int>& tree) {
	if(root->left != NULL) {
		dfs(root->left, tree);
	}
	tree.push_back(root->val);
	if(root->right != NULL) {
		dfs(root->right, tree);
	}
}
BSTIterator(TreeNode* root) {
	if(root != NULL){
		dfs(root, tree);
	}
}

bool hasNext() {
	return cur < tree.size();
}

int next() {
	return tree[cur++];
}

// solution 2: interative way

vector<int> tree;
int cur=0;

BSTIerator(TreeNode* root) {
	stack<TreeNode*> stk;
	TreeNode* tmp = root;

	while(tmp != NULL || !stk.empty()) {
		if(tmp != NULL) {
			stk.push(tmp);
			tmp = tmp->left;
		}
		else {
			tmp = stk.top();
			stk.pop();
			tree.push_back(tmp->val);
			tmp = tmp->right;
		}
	}
}

bool hasNext() {
	return cur < tree.size();
}


int next() {
	return tree[cur++];
}