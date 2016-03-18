
/*
LeetCode: sum root to leaf numbers
https://leetcode.com/problems/sum-root-to-leaf-numbers/
*/

// recursive
// dfs
// https://leetcode.com/discuss/20451/short-java-solution-recursion

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
    int sumNumbers(TreeNode* root) {
        return sumNumbers(root, 0);
    }
    int sumNumbers(TreeNode* root, int val) {
        if(root == NULL) {
            return 0;
        }
        if(!root->left && !root->right) {
            return val*10+root->val;
        }
        return sumNumbers(root->left, val*10+root->val) + sumNumbers(root->right, val*10+root->val);
        
    }
};