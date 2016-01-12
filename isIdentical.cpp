
/*
LintCode 469
Identical binary tree
检查两棵二叉树是否等价。等价的意思是说，首先两棵二叉树必须拥有相同的结构，并且每个对应位置上的节点上的数都相等。
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

/**
 * @aaram a, b, the root of binary trees.
 * @return true if they are identical, or false.
 */
bool isIdentical(TreeNode* a, TreeNode* b) {
    // Write your code here
    if(a == NULL && b == NULL) {
        return true;
    }
    if(a == NULL && b != NULL || a != NULL && b == NULL) {
        return false;
    }
    if(a->val != b->val) {
        return false;
    }
    return isIdentical(a->left, b->left) && isIdentical(a->right, b->right);
    
}