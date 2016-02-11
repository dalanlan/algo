
/*
LintCode: segment tree query II
http://www.lintcode.com/zh-cn/problem/segment-tree-query-ii/
*/

/**
 * Definition of SegmentTreeNode:
 * class SegmentTreeNode {
 * public:
 *     int start, end, count;
 *     SegmentTreeNode *left, *right;
 *     SegmentTreeNode(int start, int end, int count) {
 *         this->start = start;
 *         this->end = end;
 *         this->count = count;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     *@param root, start, end: The root of segment tree and 
     *                         an segment / interval
     *@return: The count number in the interval [start, end] 
     */
    int query(SegmentTreeNode *root, int start, int end) {
        // write your code here
        if(root == NULL) {
            return 0;
        }
        if(start <= root->start && end >= root->end) {
            return root->count;
        }
        
        int mid = (root->start + root->end)/2;
        if(start > mid) {
            return query(root->right, start, end);
        }
        if(end <= mid) {
            return query(root->left, start, end);
        }
        return query(root->left, start, mid) + query(root->right, mid+1, end); 
    }
};