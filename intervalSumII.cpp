
/*
LintCode: interval sum II
http://www.lintcode.com/zh-cn/problem/interval-sum-ii/
*/

class Solution {
public:
    /* you may need to use some attributes here */
    
    
    class TreeNode {
        public:
        int start;
        int end;
        long long sum;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int s, int e, long long su) {
            start = s;
            end = e;
            sum = su;
            left = right = NULL;
        }
        TreeNode(int s, int e) {
            start = s;
            end = e;
            left = right = NULL;
        }
    };
    /**
     * @param A: An integer vector
     */
    TreeNode* buildUtil(vector<int> &A, int lo, int hi) {
        if(lo > hi) {
            return NULL;
        }
        if(lo == hi) {
            return new TreeNode(lo, hi, A[lo]);
        }
        int mid = (lo+hi)/2;
        TreeNode *root = new TreeNode(lo, hi);
        root->left = buildUtil(A, lo, mid);
        root->right = buildUtil(A, mid+1, hi);
        root->sum = root->left->sum + root->right->sum;
        return root;
    }
    // construction function
    Solution(vector<int> A) {
        // write your code here
        root = buildUtil(A, 0, A.size()-1);
        
    }
    TreeNode *root=NULL;
    /**
     * @param start, end: Indices
     * @return: The sum from start to end
     */
    long long query(int start, int end) {
        // write your code here
        return queryUtil(root, start, end);
    }
    long long queryUtil(TreeNode *root, int start, int end) {
        if(root == NULL || start > root->end || end < root->start) {
            return 0;
        }
        if(start <= root->start && end >= root->end) {
            return root->sum;
        }
        
        int mid = (root->start + root->end)/2;
        if(start > mid) {
            return queryUtil(root->right, start, end);
        }
        if(end <= mid) {
            return queryUtil(root->left, start, end);
        }
        return queryUtil(root->left, start, mid) + queryUtil(root->right, mid+1, end);
    }
    /**
     * @param index, value: modify A[index] to value.
     */
    void modify(int index, int value) {
        // write your code here
        return modifyUtil(root, index, value);
    }
    void modifyUtil(TreeNode *root, int index, int value) {
        if(root == NULL || index > root->end || index < root->start) {
            return;
        }
        if(root->start == index && root->end == index) {
            root->sum = value;
            return;
        }
        int mid = (root->start + root->end)/2;
        if(index > mid) {
            modifyUtil(root->right, index, value);
        }
        else {
            modifyUtil(root->left, index, value);
        }
        root->sum = (root->left?root->left->sum:0) + (root->right?root->right->sum:0);
        
    }
};
