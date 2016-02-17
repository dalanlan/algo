
/*
LintCode: interval min number
http://www.lintcode.com/zh-cn/problem/interval-minimum-number/
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
    int start, end;
    int mini;
    TreeNode *left, *right;
    TreeNode(int s, int e, int m) {
        start =s;
        end = e;
        mini = m;
        left = right = NULL;
    }
    TreeNode(int s, int e) {
        start = s;
        end = e;
        left = right = NULL;
    }
};
    TreeNode* build(vector<int> &A) {
        if(A.size() == 0) {
            return NULL;
        }
        TreeNode* root=buildUtil(A, 0, A.size()-1);
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
        TreeNode* root = new TreeNode(lo, hi);
        root->left = buildUtil(A, lo, mid);
        root->right = buildUtil(A, mid+1, hi);
        root->mini = min(root->left->mini, root->right->mini);
        
        return root;
    }
    int query(TreeNode* root, int start, int end) {
        if(start > root->end || end < root->start) {
            return INT_MAX;
        }
        if(start <= root->start && end >= root->end) {
            return root->mini;
        }
        int mid = (root->start + root->end)/2;
        if(start > mid) {
            return query(root->right, start, end);
        }
        if(end <= mid) {
            return query(root->left, start, end);
        }
        return min(query(root->left, start, mid), query(root->right, mid+1, end));
        
    }
    vector<int> intervalMinNumber(vector<int> &A, vector<Interval> &queries) {
        // write your code here
        
        TreeNode* root = build(A);
        vector<int> res;
        for(int i=0; i<queries.size(); i++) {
            res.push_back(query(root, queries[i].start, queries[i].end));
        }
        return res;
    }
};