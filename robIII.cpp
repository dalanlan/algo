
/*
LeetCode: house robber iii
https://leetcode.com/problems/house-robber-iii/
*/

// rob this node or not
// dfs
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
   int rob(TreeNode* root) {
	
	vector<int> dp = robHelper(root);
	return max(dp[0], dp[1]);
}

vector<int> robHelper(TreeNode* root) {
	if(root == NULL) {
		return vector<int>(2,0);
	}

	vector<int> left = robHelper(root->left);
	vector<int> right = robHelper(root->right);

	vector<int> res;
	// res[0] : pick up root
	res.push_back(left[1] + right[1] + root->val);
	// res[1] : no root obviously
	res.push_back(max(left[0],left[1]) + max(right[0],right[1]));
	return res;

} 
};

// solution 2: rewrite

int rob(TreeNode* root) {
    pair<int,int> p=robHelper(root);
    return max(p.first,p.second);
}
pair<int,int> robHelper(TreeNode* root) {
    if(root==NULL) {
        return make_pair(0,0);
    }
    pair<int,int> left = robHelper(root->left);
    pair<int,int> right = robHelper(root->right);
    
    int first = left.second+right.second+root->val;
    int second = max(left.first, left.second) + max(right.first, right.second);
    return make_pair(first, second);
} 