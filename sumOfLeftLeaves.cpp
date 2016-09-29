

/*
LeetCode: sum of left leaves

https://leetcode.com/problems/sum-of-left-leaves/

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
    
    bool isLeave(TreeNode *root) {
        return root && !root->left && !root->right;
    }
    
    void dfs(TreeNode* root, int& num) {
        if(!root) {
            return;
        }
        if(isLeave(root->left)) {
            num += root->left->val;
        }
        else {
            dfs(root->left, num);
        }
        
        dfs(root->right, num);
        
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        int num = 0;
        dfs(root, num);    
        return num;
    }
};