
/*
LintCode: binary search tree iterator

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
 * Example of iterate a tree:
 * BSTIterator iterator = BSTIterator(root);
 * while (iterator.hasNext()) {
 *    TreeNode * node = iterator.next();
 *    do something for node
 */
class BSTIterator {
public:
    int ind=0;
    int sz=0;
    vector<TreeNode*> v;
    //@param root: The root of binary tree.
    BSTIterator(TreeNode *root) {
        // write your code here
        
        // inorder traversal 
        stack<TreeNode*> s;
        TreeNode* tmp = root;
        while(tmp != NULL || !s.empty()) {
            if(tmp != NULL) {
                s.push(tmp);
                tmp = tmp->left;
            }
            else {
                tmp = s.top();
                s.pop();
                v.push_back(tmp);
                tmp = tmp->right;
            }
        }
        sz = v.size();
    }

    //@return: True if there has next node, or false
    bool hasNext() {
        // write your code here
        return ind < sz;
    }
    
    //@return: return next node
    TreeNode* next() {
        // write your code here
        return v[ind++];
    }
};