
/*
LeetCode: search a 2D matrix II
https://leetcode.com/problems/search-a-2d-matrix-ii/
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // from right-bottom
        // when current element is less then target,
        // go down
        // otherwise go left
        if(matrix.size() == 0 || matrix[0].size() == 0) {
            return false;
        }
        
        int row = matrix.size();
        int col = matrix[0].size();
        
        int i=0, j=col-1;
        while(i<row && j>=0) {
            if(matrix[i][j] == target) {
                return true;
            }
            else if(matrix[i][j] > target) {
                j--;
            }
            else {
                i++;
            }
        }
        return false;
    }
};