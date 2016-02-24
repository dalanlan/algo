
/*
LintCode: set matrix zeroes
http://www.lintcode.com/zh-cn/problem/set-matrix-zeroes/#
*/

class Solution {
public:
    /**
     * @param matrix: A list of lists of integers
     * @return: Void
     */

     // solution 1: O(M+N) extra space complexity

    void setZeroes(vector<vector<int> > &matrix) {
        // write your code here
        
        int row = matrix.size();
        
        if(row == 0) {
            return;
        }
        int col = matrix[0].size();
       
        vector<int> rows = vector<int>(row, 0);
        vector<int> cols = vector<int>(col, 0);
        
        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                if(matrix[i][j] == 0) {
                    rows[i] = 1;
                    cols[j] = 1;
                }
            }
        }
        
        
        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                if(rows[i] == 1) {
                    matrix[i][j] = 0;
                }        
                else if(cols[j] == 1) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

// solution: no extra space solution
// use matrix to store its original result
    void setZeroes(vector<vector<int> > &matrix) {
        if(matrix.size() == 0 || matrix[0].size()==0) {
            return;
        }
        int row = matrix.size();
        int col = matrix[0].size();
        bool zeroRow0=false, zeroCol0=false;
        
        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                if(i==0 && matrix[i][j] == 0) {
                    zeroRow0 = true;
                }
                if(j==0 && matrix[i][j] == 0) {
                    zeroCol0 = true;
                }
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for(int i=1; i<row; i++) {
            for(int j=1; j<col; j++) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        if(zeroRow0) {
            for(int i=0; i<col; i++) {
                matrix[0][i] = 0;
            }
        }
        if(zeroCol0) {
            for(int i=0; i<row; i++) {
                matrix[i][0] = 0;
            }
        }
    }