
/*
LintCode: count of smaller number
http://www.lintcode.com/zh-cn/problem/count-of-smaller-number/
*/




class Solution {
public:
   /**
     * @param A: An integer array
     * @return: The number of element in the array that 
     *          are smaller that the given integer
     */
    
    
    class SegmentTreeNode {
        public:
        int count;
        int start;
        int end;
        
        SegmentTreeNode *left;
        SegmentTreeNode *right;
        
        SegmentTreeNode(int s, int e, int c) {
            start = s;
            end = e;
            count = c;
            left = right = NULL;
        }
        };
    SegmentTreeNode* build(vector<int> &A) {
        sort(A.begin(), A.end());
        if(A.size() == 0) {
            return NULL;
        }
        SegmentTreeNode *root = build(A, 0, A.size()-1);
        return root;
    }
    
    SegmentTreeNode* build(vector<int> &A, int lo, int hi) {
        if(lo > hi) {
            return NULL;
        }
        if(lo == hi) {
            return new SegmentTreeNode(A[lo], A[hi], 1);
        }
        SegmentTreeNode *root = new SegmentTreeNode(A[lo], A[hi], hi-lo+1);
        // count refers to the number that 
        // greater than A[lo], and less than
        // A[hi]
    
        int mid = (lo+hi)/2;
        root->left = build(A, lo, mid);
        root->right = build(A, mid+1, hi);
        return root;
        
    }
    int query(SegmentTreeNode *root, int target) {
        if(root == NULL) {
            return 0;
        }
        // case 1
        if(target > root->end) {
            return root->count;
        }
        // case 2
        if(target <= root->start) {
            return 0;
        }
        return query(root->left, target)+query(root->right, target);
        
    }
    vector<int> countOfSmallerNumber(vector<int> &A, vector<int> &queries) {
        // write your code here
        SegmentTreeNode *root = build(A);
        vector<int> res;
        for(int i=0; i<queries.size(); i++) {
            res.push_back(query(root, queries[i]));
        }
        return res;
        
        
    }
};