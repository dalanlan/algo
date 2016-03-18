
/*
LintCode: binary tree zigzag level order traversal
http://www.lintcode.com/zh-cn/problem/binary-tree-zigzag-level-order-traversal/
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
 
// solution 1: plain idea
// AC
class Solution {
    /**
     * @param root: The root of binary tree.
     * @return: A list of lists of integer include 
     *          the zigzag level order traversal of its nodes' values 
     */
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        // write your code here
        vector<vector<int> > res;
        if(root == NULL) {
            return res;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        bool isLeft = true;
        while(!q.empty()) {
            int sz = q.size();
            vector<int> level;
            for(int i=0; i<sz; i++) {
                TreeNode *tmp = q.front();
                q.pop();
                level.push_back(tmp->val);
                if(tmp->left) {
                    q.push(tmp->left);
                }
                if(tmp->right) {
                    q.push(tmp->right);
                }
            }
            if(!isLeft) {
                reverse(level.begin(), level.end());
            }
            res.push_back(level);
            isLeft = !isLeft;
        }
        return res;
    }
};


// still an intuitive idea

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        // no reverse operation
        
        vector<vector<int> > res;
        if(root == NULL) {
            return res;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        bool isLeft = true;
        while(!q.empty()) {
            int sz = q.size();
            vector<int> level(sz, 0);
            for(int i=0; i<sz; i++) {
                
                TreeNode* tmp = q.front();
                q.pop();
                if(isLeft) {
                    level[i] = tmp->val;
                }
                else {
                    level[sz-i-1] = tmp->val;
                }
                if(tmp->left) {
                    q.push(tmp->left);
                }
                if(tmp->right) {
                    q.push(tmp->right);
                }
            }
            res.push_back(level);
            isLeft = !isLeft;
        }
        return res;
    }
};