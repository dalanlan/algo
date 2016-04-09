
/*
Leetcode: kth smallest element in a binary search tree
https://leetcode.com/problems/kth-smallest-element-in-a-bst/
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
    
    
    int countTree(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        return countTree(root->left) + countTree(root->right)+1;
    }

    int kthSmallest(TreeNode* root, int k) {

        int left = countTree(root->left);
        if(k <= left) {
            return kthSmallest(root->left, k);
        }
        else if(k==left+1) {
            return root->val;
        }
        else {
            return kthSmallest(root->right, k-1-left);
        }
        
    }
};


// solution: also a kinda brilliant solution

    
    
    int kthSmallest(TreeNode* root, int k) {
        
        stack<TreeNode*> stk;
        while(root) {
            stk.push(root);
            root = root->left;
        }
        while(k!=0) {
            TreeNode* tmp = stk.top();
            stk.pop();
            TreeNode *right = tmp->right;
            
            k--;
            if(k==0) {
                return tmp->val;
            }
            // here we use `while`
            // do figure out why
            while(right) {
                stk.push(right);
                right = right->left;
            }
        }
        return -1;
        
    }