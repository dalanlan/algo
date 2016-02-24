
/*
LintCode: construct binary tree from preorder and inorder traversal
http://www.lintcode.com/zh-cn/problem/construct-binary-tree-from-preorder-and-inorder-traversal/
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
     *@param preorder : A list of integers that preorder traversal of a tree
     *@param inorder : A list of integers that inorder traversal of a tree
     *@return : Root of a tree
     */
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // write your code here
        int sz = preorder.size();
        return buildTree(preorder, 0, sz-1, inorder, 0, sz-1);
    }
    
    TreeNode *buildTree(vector<int> &preorder, int s1, int e1, vector<int> &inorder, int s2, int e2) {
        if(s1 > e1 || s2 > e2) {
            return NULL;
        }
        if(s1 == e1 || s2 == e2) {
            return new TreeNode(preorder[s1]);
        }
        TreeNode *root = new TreeNode(preorder[s1]);
        int pos=s2; 
        while(pos<e2 && inorder[pos] != preorder[s1]) {
            pos++;
        }
        // inorder[pos] == root->val;
        root->left = buildTree(preorder, s1+1, pos-s2+s1, inorder, s2, pos-1);
        root->right = buildTree(preorder, pos-s2+s1+1, e1, inorder, pos+1, e2);
        return root;
    }
};