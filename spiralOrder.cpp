
/*
LintCode: sprial matrix
http://www.lintcode.com/zh-cn/problem/spiral-matrix/#iv
*/

class Solution {
public:
    /**
     * @param matrix a matrix of m x n elements
     * @return an integer array
     */
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // Write your code here
        int row = matrix.size();
        vector<int> res;
        if(row == 0) {
            return res;
        }
        int col = matrix[0].size();
        if(col == 0) {
            return res;
        }
        
        int count =0; 
        
        while(count * 2 < row && count*2 <col) {
            for(int i=count; i<col-count; i++) {
                res.push_back(matrix[count][i]);
            }
            for(int i=count+1; i<row-count; i++) {
                res.push_back(matrix[i][col-count-1]);
            }
            if(row - 2*count == 1 || col-2*count == 1) {
                break;
            }
            for(int i=col-count-2; i>=count; i--) {
                res.push_back(matrix[row-count-1][i]);
            }
            for(int i=row-count-2; i>=count+1; i--) {
                res.push_back(matrix[i][count]);
            }
            count++;
        }
        return res;
        
    }
};