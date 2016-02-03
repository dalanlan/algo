
/*
LintCode: balanced binary tree
http://www.lintcode.com/zh-cn/problem/balanced-binary-tree/
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
     * @param root: The root of binary tree.
     * @return: True if this Binary tree is Balanced, or false.
     */

    int helper(TreeNode* root) {
    	if(root == NULL) {
    		return 0;
    	}
    	int left = helper(root->left);
    	int right = helper(root->right);
    	if(left == -1 || right == -1 || abs(left- right) > 1) {
    		return -1;
    	}
    	return max(left, right) + 1;
    	
    }
    bool isBalanced(TreeNode *root) {
        // write your code here
        int res = helper(root);
        if(res == -1) {
        	return false;
        }
        return true;
    }
};