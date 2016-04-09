
/*
LeetCode: count complete tree nodes
https://leetcode.com/problems/count-complete-tree-nodes/
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
    int countHeight(TreeNode* root) {
        if(!root) {
            return -1;
        }
        else {
            return 1+countHeight(root->left);
        }
    }
    int countNodes(TreeNode* root) {
        int h = countHeight(root);
        if(h < 0) {
            return 0;
        }
        if(h-1 == countHeight(root->right)) {
            return (1<<h)+countNodes(root->right);
        }
        else {
            return (1<<h-1) + countNodes(root->left);
        }
    }
};


// iterative solution

    int countNodes(TreeNode* root) {
        int h = countHeight(root);
        int count = 0;
        TreeNode *cur = root;
        
        while(cur) {
            if(countHeight(cur->right) == h-1) {
                count += 1<<h;
                cur= cur->right;
            }
            else {
                count += 1<<h-1;
                cur = cur->left;
            }
            h--;
        }
        return count;
    }