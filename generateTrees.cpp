// Unique Binary Search Trees II

/*
Given n, generate all structurally unique BST's 
that store value 1...n
*/

vector<TreeNode*> get(int left, int right) {
	vector<TreeNode*> res;

	if(left > right) {
		res.push_back(NULL);
	}
	TreeNode* tmp;
	for(int i=left; i <= right; i++) {
		for(auto l : get(left, i-1)) {
			for(auto r: get(i+1, right)) {
				tmp = new TreeNode(i);
				tmp->left = l;
				tmp->right = r;
				res.push_back(tmp);
			}
		}
	}
	return res;


}
vector<TreeNode*> generateTrees(int n) {
	vector<TreeNode*> res;
	if(n == 0) {
	    return res;
	}
	return get(1, n);
	
}