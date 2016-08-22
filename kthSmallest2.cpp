

/*
Leetcode: kth Smallest Element in a sorted matrix
https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
*/
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int row = matrix.size();
        int col = row == 0?0:matrix[0].size();
        
        if(row == 0 || col == 0) {
            return INT_MAX;
        }
        
        // pair -- [value; index]
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>> > pq;
        // pq.push(make_pair(matrix[0][0], 0));
        for(int i=0; i < col; i++) {
            pq.push(make_pair(matrix[0][i], i));
        }
        
        pair<int, int> cur;
        for(int i=0; i<k; i++) {
            cur = pq.top();
            pq.pop();
            
            int r = cur.second/col;
            int c = cur.second%col;
            if(r < row-1) {
                pq.push(make_pair(matrix[r+1][c], (r+1)*col+c));
            }
            
        }
            
        return cur.first;
        
    }
};