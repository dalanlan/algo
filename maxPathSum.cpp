
/*
LintCode: binary tree maximum path sum
http://www.lintcode.com/zh-cn/problem/binary-tree-maximum-path-sum/#
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
    class ResultType {
        public:
        int singlePath;
        int maxPath;
        ResultType(int s, int m) {
            this->singlePath = s;
            this->maxPath = m;
        }
};

    /**
     * @param root: The root of binary tree.
     * @return: An integer
     */
     ResultType* helper(TreeNode *root) {
         if(root == NULL) {
             return new ResultType(0, INT_MIN);
         }
         
         ResultType* left = helper(root->left);
         ResultType* right = helper(root->right);
         
         int singlePath = max(left->singlePath, right->singlePath) + root->val;
         singlePath = max(singlePath, 0);
         
         int maxPath = max(left->maxPath, right->maxPath);
         maxPath = max(maxPath, left->singlePath + right->singlePath + root->val);
         
         return new ResultType(singlePath, maxPath);
         
     }
    int maxPathSum(TreeNode *root) {
        ResultType *res = helper(root);
        return res->maxPath;
    }
};


// solution 2: https://leetcode.com/discuss/14190/accepted-short-solution-in-java
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
    int maxPathSum(TreeNode* root) {
        int maxPath = INT_MIN;
        maxPathSum(root, maxPath);
        return maxPath;
    }
    int maxPathSum(TreeNode* root, int & maxPath) {
        if(root == NULL) {
            return 0;
        }
        int left = max(0, maxPathSum(root->left, maxPath));
        int right = max(0, maxPathSum(root->right, maxPath));
        maxPath = max(maxPath, left + right + root->val);
        return max(left, right)+root->val;
    }
};