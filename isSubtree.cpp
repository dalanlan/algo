
/*
LintCode: Subtree
http://www.lintcode.com/zh-cn/problem/subtree/#
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
     * @param T1, T2: The roots of binary tree.
     * @return: True if T2 is a subtree of T1, or false.
     */
    bool validate(TreeNode *T1, TreeNode *T2) {
        if(T2 == NULL && T1 == NULL) {
            return true;
        }
        if(T1 == NULL || T2 == NULL) {
            return false;
        }
        if(T1->val != T2->val) {
            return false;
        }
        if(!validate(T1->left, T2->left) || !validate(T1->right, T2->right)) {
            return false;
        }
        return true;
        
    }
    bool isSubtree(TreeNode *T1, TreeNode *T2) {
        if(T2 == NULL) {
            return true;
        }
        else if(T1 == NULL) {
            return false;
        }
        else return validate(T1, T2) || isSubtree(T1->left, T2) || isSubtree(T1->right, T2);
    }
};