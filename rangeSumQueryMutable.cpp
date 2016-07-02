
/*
LeetCode: range sum query mutable
https://leetcode.com/problems/range-sum-query-mutable/

Given an integer array nums, find the sum of 
the elements between indices i and j (i ≤ j), inclusive.

The update(i, val) function modifies nums by updating the 
element at index i to val.

*/

class NumArray {
	public:
		struct TreeNode {
			int start;
			int end;
			int val;
			TreeNode* left = NULL;
			TreeNode* right = NULL;
			TreeNode(int s, int e, int v) {
				start = s;
				end = e;
				val = v;
			}
			TreeNode(int s, int e) {
				start = s;
				end = e;
			}	
		};

		TreeNode *root;

		TreeNode* constructTree(vector<int>& nums, int lo, int hi) {
			if(nums.size() == 0 || hi < lo) {
				return NULL;
			}

			TreeNode* cur = new TreeNode(lo, hi);
			if(hi == lo) {
				cur->val = nums[lo];
				return cur;
			}

			int mid = (lo+hi)/2;
			cur->left = constructTree(nums, lo, mid);
			cur->right = constructTree(nums, mid+1, hi);
			cur->val = cur->left->val+cur->right->val;
			return cur;

		}

		NumArray(vector<int>& nums) {
			root = constructTree(nums, 0, nums.size()-1);
		}

		void update(TreeNode* root, int i, int val) {
			if(i == root->start && i == root->end) {
				root->val = val;
				return;
			}
			int mid = (root->start+root->end)/2;
			if(i <= mid) {
				update(root->left, i, val);
			}
			else {
				update(root->right, i, val);
			}
			root->val = root->left->val + root->right->val;
		}

		void update(int i, int val) {
			update(root, i, val);
		}

		int sumRange(TreeNode* root, int i, int j) {
			if(i==root->start && j == root->end) {
				return root->val;
			}
			int mid = (root->start + root->end)/2;
			if(i > mid) {
				return sumRange(root->right, i, j);
			}
			else if(j <= mid) {
				return sumRange(root->left, i, j);
			}
			else {
				return sumRange(root->left, i, mid) + sumRange(root->right, mid+1, j);
			}
		}

		int sumRange(int i, in j) {
			return sumRange(root, i, j);
		}
};