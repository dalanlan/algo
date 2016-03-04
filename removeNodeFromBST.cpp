
/*
LintCode: remove node in binary search tree
http://www.lintcode.com/zh-cn/problem/remove-node-in-binary-search-tree/
*/


// This is an odd solution
// Find the min val in the right subtree of the 
// certain node 
// swap its value with node value

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
     * @param root: The root of the binary search tree.
     * @param value: Remove the node with given value.
     * @return: The root of the binary search tree after removal.
     */
     
    TreeNode* findNode(TreeNode* parent, TreeNode* root, int value) {
        if(root == NULL) {
            return parent;
        }
        if(root->val == value) {
            return parent;
        }
        if(root->val > value) {
            // find left tree
            return findNode(root, root->left, value);
        }
        else {
            return findNode(root, root->right, value);
        }
    }
    
    TreeNode* removeNode(TreeNode* root, int value) {
        TreeNode *dummy = new TreeNode(0);
        dummy->left = root;
        
        
        TreeNode *parent = findNode(dummy, root, value);
        // it wont return NULL whether we find out the
        // particular node or not
        if(parent->left && parent->left->val == value) {
            deleteNode(parent, parent->left);
        }
        else if(parent->right && parent->right->val == value) {
            deleteNode(parent, parent->right);
        }
        return dummy->left;
        
        
    }
    // find minimum value in the subtree of the certain node
    int minVal(TreeNode *node) {
        if(node->left == NULL) {
            return node->val;
        }
        return minVal(node->left);
    }
    void deleteNode(TreeNode* parent, TreeNode* node) {
        // both left subtree and right subtree
        if(node->left != NULL && node->right != NULL) {
            int minRightVal = minVal(node->right);
            TreeNode* p = findNode(node, node->right, minRightVal);
            if(p->left && p->left->val == minRightVal) {
                deleteNode(p, p->left);
            }
            else {
                deleteNode(p, p->right);
            }
            node->val = minRightVal;
            
        }
        else if(parent->left == node) {
            parent->left = (node->left!=NULL)?(node->left):(node->right);
        }
        else if(parent->right == node) {
            parent->right = (node->left!=NULL)?(node->left):(node->right);
        }
    }
};

// clean and neat
    TreeNode* removeNode(TreeNode* root, int value) {
        TreeNode* dummy = new TreeNode(0);
        dummy->left = root;
        TreeNode* pre = dummy, *cur = root;
        
        while(cur) {
            if(cur->val > value) {
                // explore right subtree
                pre = cur;
                cur = cur->left;
            }
            else if(cur->val < value) {
                pre = cur;
                cur = cur->right;
            }
            else {
                if(pre->left == cur) {
                    pre->left = removeNode(cur);
                }
                else {
                    pre->right = removeNode(cur);
                }
                break;
            }
        }
        return dummy->left;
    }     
    TreeNode* removeNode(TreeNode* node) {
        if(!node->left && !node->right) {
            return NULL;
        }
        if(!node->left || !node->right) {
            return (node->left)?(node->left):(node->right);
        }
        TreeNode *child = node->left->right;
        TreeNode *parent = node->right;
        while(parent->left) {
            parent = parent->left;
        }
        parent->left = child;
        node->left->right = node->right;
        return node->left;
    }