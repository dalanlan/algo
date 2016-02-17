
/*
LintCode: binary tree level order traversal ii 
http://www.lintcode.com/zh-cn/problem/binary-tree-level-order-traversal-ii/
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
     * @param root : The root of binary tree.
     * @return : buttom-up level order a list of lists of integer
     */
public:
    vector<vector<int>> levelOrderBottom(TreeNode *root) {
        // write your code here
        vector<vector<int>> res;
        if(root==NULL) {
            return res;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int sz = q.size();
            vector<int> level;
            for(int i=0; i<sz; i++) {
                TreeNode* tmp = q.front();
                q.pop();
                level.push_back(tmp->val);
                if(tmp->left) {
                    q.push(tmp->left);
                }
                if(tmp->right) {
                    q.push(tmp->right);
                }
            }
            res.push_back(level);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};