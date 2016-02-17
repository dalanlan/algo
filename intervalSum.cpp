
/*
LintCode: interval sum
http://www.lintcode.com/zh-cn/problem/interval-sum/
*/

/*
This is also about segment tree
tips:
1) About the mid split
2) about res: long long instead of int
*/

/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 */
class Solution { 
public:
    /**
     *@param A, queries: Given an integer array and an query list
     *@return: The result list
     */
    class TreeNode {
    public:
        int start;
        int end;
        long long sum;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int s, int e, long long su) {
            start = s;
            end = e;
            sum = su;
            left = right = NULL;
        }
        TreeNode(int s, int e) {
            start = s;
            end = e;
        }
    };
    
    TreeNode* build(vector<int> &A) {
        TreeNode *root = buildUtil(A, 0, A.size()-1);
        return root;
    } 
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
    long long query(TreeNode* root, int start, int end) {
        if(start == root->start && end == root->end) {
            return root->sum;
        }
        if(start > root->end || end < root->start) {
            return 0;
        }
        int mid = (root->start + root->end)/2;
        if(end <= mid) {
            return query(root->left, start, end);
        }
        if(start > mid) {
            return query(root->right, start, end);
        }
        return query(root->left, start, mid) + query(root->right, mid+1, end);
    }
    
    vector<long long> intervalSum(vector<int> &A, vector<Interval> &queries) {
        // write your code here
        TreeNode* root = build(A);
        vector<long long> res;
        for(int i=0; i<queries.size(); i++) {
            res.push_back(query(root, queries[i].start, queries[i].end));
        }
        return res;
    }
};