
/*
Leetcode: 
https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
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
    void flatten(TreeNode* root) {
        // bfs
        if(!root) {
            return;
        }
        deque<TreeNode*> q1;
        q1.push_back(root);
        queue<TreeNode*> q2;
        while(!q1.empty()) {
            TreeNode* tmp = q1.front();
            q1.pop_front();
            
            q2.push(tmp);
            if(tmp->right) {
                q1.push_front(tmp->right);
            }
            if(tmp->left) {
                q1.push_front(tmp->left);
            }
        }
        while(!q2.empty()) {
            TreeNode* tmp = q2.front();
            q2.pop();
            tmp->left = NULL;
            tmp->right = q2.empty()?NULL:q2.front();
        }
        
    }
};