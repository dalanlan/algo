
/*
LintCode: search a 2d matrix
http://www.lintcode.com/zh-cn/problem/search-a-2d-matrix/
*/

// solution 1: binary search
// Use the order to be the search index

class Solution {
public:
    /**
     * @param matrix, a list of lists of integers
     * @param target, an integer
     * @return a boolean, indicate whether matrix contains target
     */
     
    
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // write your code here
        if(matrix.size() == 0 || matrix[0].size() == 0) {
            return false;
        }
        
        // binary search
        int row = matrix.size();
        int col = matrix[0].size();
        int lo = 0;
        int hi = row*col-1;
        
        int mid, midNum;
        while(lo <= hi) {
            mid = (lo+hi)/2;
            midNum = matrix[mid/col][mid%col];
            if(midNum == target) {
                return true;
            }
            else if(midNum < target) {
                lo = mid+1;
            }
            else {
                hi = mid-1;
            }
            
        }
        return false;
        
    }
};


