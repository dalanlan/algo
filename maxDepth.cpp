
/*
Lintcode 97: max depth of a binary tree
The depth of a tree is the distance between 
tree node and root node.
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
     * @return: An integer
     */
    
    int helper(TreeNode *root, int index) {
        if(root == NULL) {
            return index;
        }
        
        if(root->left == NULL && root->right == NULL) {
            return index+1;    
        }
        
        return max(helper(root->left, index+1), helper(root->right, index+1));
    }
    int maxDepth(TreeNode *root) {
        // write your code here
        return helper(root, 0);
    }
};

// solution 2: rewrite
    int maxDepth(TreeNode *root) {
        if(root==NULL) {
            return 0;
        }
        return max(maxDepth(root->left),maxDepth(root->right))+1;
    } 