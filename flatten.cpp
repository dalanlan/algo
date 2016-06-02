
/* LintCode 453:
Change binary tree to a fake linked list
A faked linked list is said to be some linked list
with a `right` pointer in the tree instead of a `next`
pointer in the linked list.

              1
               \
     1          2
    / \          \
   2   5    =>    3
  / \   \          \
 3   4   6          4
                     \
                      5
                       \
                        6

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
     * @param root: a TreeNode, the root of the binary tree
     * @return: nothing
     */
        
    void dfs(TreeNode* root, queue<TreeNode*> &q) {
        if(!root) {
            return;
        }
        q.push(root);
        dfs(root->left,q);
        dfs(root->right,q);
    }
    void flatten(TreeNode* root) {
        queue<TreeNode*> q;
        dfs(root, q);
        while(!q.empty()) {
            TreeNode* tmp = q.front();
            q.pop();
            tmp->left = NULL;
            tmp->right = q.empty()?NULL:q.front();
        }
    }
};