
/*
LintCode: search a 2d matrix ii
http://www.lintcode.com/zh-cn/problem/search-a-2d-matrix-ii/
*/

class Solution {
public:
    /**
     * @param matrix: A list of lists of integers
     * @param target: An integer you want to search in matrix
     * @return: An integer indicate the total occurrence of target in the given matrix
     */
    int searchMatrix(vector<vector<int> > &matrix, int target) {
        // write your code here
        
        // return the count
        // narrow down the search range
        int count = 0;
        if(matrix.size() == 0 || matrix[0].size() == 0) {
            return count;
        }
        
        int row = matrix.size();
        int col = matrix[0].size();
        
        
        // from left-bottom or right-up
        // say we start from left bottom
        int i= row-1, j=0;
        int cur;
        while(i >= 0 && i < row && j >=0 && j < col) {
            cur = matrix[i][j];
            if(cur == target) {
                count++;
                j++;
                i--;
            }
            else if(cur > target) {
                i--;
            }
            else {
                j++;
            }
        }
        return count;
        
    }
};
