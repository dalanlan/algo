
/*
LintCode 85: insert a node into a binary search tree
*/

// solution 1: recursive

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
     * @param node: insert this node into the binary search tree
     * @return: The root of the new binary search tree.
     */
    TreeNode* insertNode(TreeNode* root, TreeNode* node) {
        if(root == NULL) {
        	return node;
        }

        if(node->val < root->val) {
        	if(root->left == NULL) {
        		root->left = node;
        	}
        	else {
        		insertNode(root->left, node);
        	}
        }
        if(node->val > root->val) {
        	if(root->right == NULL) {
        		root->right = node;
        	}
        	else {
        		insertNode(root->right, node);
        	}
        }
        return root;

    }
};

// solution 2: iterative 

TreeNode* insertNode(TreeNode* root, TreeNode* node) {
	if(root == NULL) {
		return node;
	}
	queue<TreeNode*> q;
	q.push(root);
	while(!q.empty()) {
		TreeNode* tmp = q.front();
		q.pop();
		if(tmp->val < node->val) {
			if(tmp->right == NULL) {
				tmp->right = node;
				break;
			}
			else {
				q.push(tmp->right);
			}
		}
		else {
			if(tmp->left == NULL) {
				tmp->left = node;
				break;
			}
			else {
				q.push(tmp->left);
			}
		}
	}
	return root;
}