
/*
Leetcode: search a 2D matrix
https://leetcode.com/problems/search-a-2d-matrix/
*/

// binary search

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        if(matrix.size() == 0 || matrix[0].size() == 0) {
            return false;
        }
        
        int row = matrix.size();
        int col = matrix[0].size();
        
        int lo = 0, hi = row*col-1;
        while(lo <= hi) {
            int mid = (lo + hi)/2;
            int r = mid/col;
            int c = mid%col;
            if(matrix[r][c] == target) {
                return true;
            }
            else if(matrix[r][c] < target) {
                lo = mid+1;
            }
            else {
                hi = mid-1;
            }
        }
        return false;
    }
};