
/*
LintCode: minimum depth of binary tree
http://www.lintcode.com/zh-cn/problem/minimum-depth-of-binary-tree/
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


// solution 1: recursive
int minDepth(TreeNode* root) {
    if(root == NULL) {
        return 0;
    }
    int lf = minDepth(root->left);
    int rt = minDepth(root->right);
    return (lf==0 || rt == 0)?lf+rt+1:min(lf, rt)+1;
}
// solution 2: iterative
class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: An integer
     */
    int minDepth(TreeNode *root) {
        // write your code here
        
        // BST
        // level order traversal
        
        
        if(root == NULL) {
            return 0;
        }
        int depth = 0;
        queue<TreeNode*> q;
        q.push(root);
        
        
        while(!q.empty()) {
            int sz = q.size();
            depth++;
            for(int i=0; i<sz; i++) {
                
                TreeNode* cur = q.front();
                q.pop();
                if(!cur->left && !cur->right) {
                    return depth;
                }
                if(cur->left) {
                    q.push(cur->left);
                }
                if(cur->right) {
                    q.push(cur->right);
                }
            }
        }
        return depth;
    }
};