
/*
LintCode: construct binary tree from inorder and postorder traversal
http://www.lintcode.com/zh-cn/problem/construct-binary-tree-from-inorder-and-postorder-traversal/
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
    /**
     *@param inorder : A list of integers that inorder traversal of a tree
     *@param postorder : A list of integers that postorder traversal of a tree
     *@return : Root of a tree
     */
public:

    TreeNode *build(vector<int> &inorder, int lo, int hi, vector<int> &postorder, int lo2, int hi2) {
        if(lo > hi) {
            return NULL;
        }
        TreeNode* root = new TreeNode(postorder[hi2]);
        if(lo2==hi2){
            return root;
        }
        int pos=lo;
        while(inorder[pos] != postorder[hi2]) {
            pos++;
        }
        
        root->left = build(inorder, lo, pos-1, postorder, lo2, lo2+pos-1-lo);
        root->right = build(inorder, pos+1, hi, postorder, lo2+pos-lo, hi2-1);
        return root;
        
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // write your code here
        int sz = inorder.size();
        return build(inorder, 0, sz-1, postorder, 0, sz-1);
    }
};