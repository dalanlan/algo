
/*
LintCode: matrix zigzag traversal
http://www.lintcode.com/zh-cn/problem/matrix-zigzag-traversal/
*/

class Solution {
public:
    /**
     * @param matrix: a matrix of integers
     * @return: a vector of integers
     */
    vector<int> printZMatrix(vector<vector<int> > &matrix) {
        // write your code here
        
        vector<int> res;
        if(matrix.size() == 0 || matrix[0].size() == 0) {
            return res;
        }
        
        int row=matrix.size();
        int col=matrix[0].size();
        
        for(int i=0; i<=row+col-2;i++) {
            // sum: i
            if(i%2 == 0) {
                //even
                for(int x=i; x>=0; x--) {
                    if(x < row && i-x < col) {
                        res.push_back(matrix[x][i-x]);
                    }
                }
            }
            else {
                for(int x=0; x<=i; x++) {
                    if(x < row && i-x < col) {
                        res.push_back(matrix[x][i-x]);
                    }
                }
            }
             
        }
        return res;
    }
};
