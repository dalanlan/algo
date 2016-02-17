
/*
LintCode: search range in binary search tree
http://www.lintcode.com/zh-cn/problem/search-range-in-binary-search-tree/#
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
class Solution {
public:
    /**
     * @param root: The root of the binary search tree.
     * @param k1 and k2: range k1 to k2.
     * @return: Return all keys that k1<=key<=k2 in ascending order.
     */
    vector<int> searchRange(TreeNode* root, int k1, int k2) {
        // write your code here
        vector<int> res;
        dfs(root, k1, k2, res);
        return res;
    }
    void dfs(TreeNode* root, int lower, int upper, vector<int> &res) {
        if(root == NULL) {
            return;
        }
        dfs(root->left, lower, upper, res);
        if(root->val >= lower && root->val <= upper) {
            res.push_back(root->val);
        }
        dfs(root->right, lower, upper, res);
        
    }
};