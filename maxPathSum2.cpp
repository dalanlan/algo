
/*
LeetCode:  binary maximum path sum
https://leetcode.com/problems/binary-tree-maximum-path-sum/
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

    int maxPathSum(TreeNode* root) {
        int maxRes = INT_MIN;
        pathHelper(root, maxRes);
        return maxRes;
    }
    
    // return the max path sum starts from any 
    // subnode of the root and ends here
    // update maxRes in the process
    int pathHelper(TreeNode* root,int& maxRes) {
        if(root == NULL) {
            return 0;
        }
        int left = max(0, pathHelper(root->left, maxRes));
        int right = max(0, pathHelper(root->right, maxRes));
        
        
        maxRes = max(maxRes, root->val+left+right);
        return root->val+max(left, right);
    }
};
