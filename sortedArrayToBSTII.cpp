
/*
LintCode 177: Convert sorted array to binary search tree
Given a sorted array, please convert it into a 
least height binary search tree.
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
     * @param A: A sorted (increasing order) array
     * @return: A tree node
     */
    TreeNode *helper(vector<int> &A, int lo, int hi) {
    	int mid = lo + ((hi-lo)>>1); // priority matters
    	TreeNode *root = new TreeNode(A[mid]);

    	if(lo < mid) {
    		root->left = helper(A, lo, mid-1);
    	}
    	if(mid < hi) {
    		root->right = helper(A, mid+1, hi);
    	}

    	return root;
    }
    TreeNode *sortedArrayToBST(vector<int> &A) {
        if(A.size() == 0) {
        	return NULL;
        }
        return helper(A, 0, A.size()-1);
    }
};


