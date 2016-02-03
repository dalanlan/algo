
/*
LintCode: submatrix sum
http://www.lintcode.com/zh-cn/problem/submatrix-sum/
*/

class Solution {
public:
    /**
     * @param matrix an integer matrix
     * @return the coordinate of the left-up and right-down number
     */
    
    vector<vector<int>> submatrixSum(vector<vector<int>>& matrix) {
        // elements are x-cord and y-cord.
        vector<vector<int>> res;
        int row = matrix.size();
        if(row == 0) {
            return res;
        }
        int col = matrix[0].size();
        if(col == 0) {
            return res;
        }
        
        vector<vector<int>> sum = vector<vector<int>>(row+1, vector<int> (col+1, 0));

       
        
        for(int i=1; i<=row; i++) {
            for(int j=1; j<=col; j++) {
                sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + matrix[i-1][j-1];
            }
        }
        
        unordered_map<int, int > myMap;
    
        for(int i=0; i<row; i++) {
            for(int j=i+1; j<=row; j++) {
                myMap.clear();
                for(int c=0; c<=col; c++) {
                    int diff = sum[j][c]-sum[i][c];
                    if(myMap.find(diff) == myMap.end()) {
                        myMap[diff] = c;
                    }
                    else {
                        vector<vector<int>> res;
                        res.push_back(vector<int>{i,myMap[diff]});
                        res.push_back(vector<int>{j-1, c-1});
                        return res;
                        
                    }
                }
            }
        }
    }
};