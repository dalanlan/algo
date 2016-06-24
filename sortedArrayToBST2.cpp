
/*

LeetCode: convert sorted array to binary search tree
https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

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
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
         return sortedArrayToBST(nums, 0, nums.size()-1);
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums, int lo, int hi) {
    	if(lo > hi) {
    		return NULL;
    	}
    	if(lo == hi) {
    		TreeNode* root = new TreeNode(nums[lo]);
    		return root;
    	}
    	int mid = (lo+hi)/2;
    	TreeNode* root = new TreeNode(nums[mid]);
    	root->left = sortedArrayToBST(nums, lo, mid-1);
    	root->right = sortedArrayToBST(nums, mid+1, hi);
    	return root;
    }

};