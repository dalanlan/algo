
/*
LintCode: unique binary search trees ii
http://www.lintcode.com/zh-cn/problem/unique-binary-search-trees-ii/
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
     * @paramn n: An integer
     * @return: A list of root
     */
    vector<TreeNode *> generateTrees(int n) {
        // write your code here
        return generateTrees(1, n);
    }
    vector<TreeNode*> generateTrees(int lo, int hi) {
        
        vector<TreeNode*> res;
        if(lo > hi) {
            res.push_back(NULL);
            return res;
        }
        for(int i=lo; i<=hi; i++) {
            vector<TreeNode*> left = generateTrees(lo, i-1);
            vector<TreeNode*> right = generateTrees(i+1, hi);
            
            for(TreeNode *m:left) {
                for(TreeNode *n:right) {
                    TreeNode* root = new TreeNode(i);
                    root->left=m;
                    root->right=n;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
};