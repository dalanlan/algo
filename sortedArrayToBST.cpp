// Converted Sorted Array to BST
// Given an array where elements are sorted in ascending order, convert 
// it to a height balanced BST

 int mid(int lo, int hi) {
	if(lo > hi) {
		return -1;
	}
	return lo + (hi-lo)/2;
	
}

TreeNode* helper(vector<int>& nums, int lo, int hi) {
	int midIndex = mid(lo, hi);
	TreeNode* root = new TreeNode(nums[midIndex]);
	if(midIndex > lo) {
		root->left = helper(nums, lo, midIndex-1);
	}
	if(midIndex < hi) {
	root->right = helper(nums, midIndex+1, hi);
	}
	return root;
}
TreeNode* sortedArrayToBST(vector<int>& nums){
    if(nums.size() == 0)
        return NULL;
	return helper(nums, 0, nums.size()-1);
}