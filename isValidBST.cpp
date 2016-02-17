
/*
LintCode: validate binary search tree
http://www.lintcode.com/zh-cn/problem/validate-binary-search-tree/
*/

// solution 1: inorder traversal 
// using a stack
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
     * @param root: The root of binary tree.
     * @return: True if the binary tree is BST, or false
     */


    bool isValidBST(TreeNode *root) {
        if(root == NULL) {
            return true;
        }
	TreeNode *tmp = root;
	stack<TreeNode*> s;
	vector<int> res;
	while(tmp != NULL || !s.empty()) {
		if(tmp != NULL) {
			s.push(tmp);
		
			tmp = tmp->left;
		}
		else {
			tmp = s.top();
			res.push_back(tmp->val);
			s.pop();
			tmp = tmp->right;

		}
	}
	for(int i=0; i<res.size()-1; i++) {
		if(res[i] >= res[i+1]) {
			return false;
		}
	}
	return true;
}
};

// solution 2: set upper bound/lower bound

bool isValidBST(TreeNode* root) {
	if(root == NULL) {
		return true;
	}
	return dfs(root, (long)INT_MIN-1, (long)INT_MAX+1);
}

bool dfs(TreeNode *root, long lower, long upper) {
	if(root == NULL) {
		return true;
	}
	if(root->val <= lower || root->val >= upper) {
		return false;
	}
	return dfs(root->left, lower, root->val) && dfs(root->right, root->val, upper);
}