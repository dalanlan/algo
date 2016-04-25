
/*
LeetCode: construct binary tree from preorder and inorder traversal
https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
    
    TreeNode* buildTree(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd) {
        if(preEnd < preStart) {
            return NULL;
        }
            
        int rootVal = preorder[preStart];
        
        // rootPos is the pos of root @inorder vector
        // hence we have rootPos-inStart length of left tree
        // and inEnd-rootPos length of right tree
        int rootPos = inStart;
        for(; rootPos < inEnd; rootPos++) {
            if(inorder[rootPos] == rootVal) {
                break;
            }
        }
        
        TreeNode *root = new TreeNode(rootVal);
        root->left = buildTree(preorder, preStart+1, preStart+rootPos-inStart, inorder, inStart, rootPos-1);
        root->right = buildTree(preorder, preStart+1+rootPos-inStart, preEnd, inorder, rootPos+1, inEnd);
        return root;
    }
};