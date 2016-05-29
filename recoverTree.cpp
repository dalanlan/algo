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
    
    TreeNode* cand1 = NULL;
    TreeNode* cand2 = NULL;
    TreeNode* prev = new TreeNode(INT_MIN);
    

    void recoverTree(TreeNode* root) {
        inorderTraversal(root);

        int tmp = cand1->val;
        cand1->val = cand2->val;
        cand2->val = tmp;
    }
    
    void inorderTraversal(TreeNode* root) {
        if(!root) {
            return ;
        }
        inorderTraversal(root->left);
        
        if(!cand1 && prev->val > root->val) {
            cand1 = prev;
        }
        if(cand1 && prev->val > root->val) {
            cand2 = root;
        }
        prev = root;
        inorderTraversal(root->right);
    }
};
