
/*
Leetcode: spiral matrix
https://leetcode.com/problems/spiral-matrix/
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        
        if(matrix.size()==0 || matrix[0].size() == 0) {
            return res;
        }
        int row = matrix.size();
        int col = matrix[0].size();
        int n = min(row, col);
        int cnt = 0; // mind the min of row and col
        
        while(cnt <= (n-1)/2) {
            for(int i=cnt; i<col-cnt; i++) {
                res.push_back(matrix[cnt][i]);
            }
            for(int i=cnt+1; i<row-cnt; i++) {
                res.push_back(matrix[i][col-1-cnt]);
            }
            if(cnt == n/2) {
                break;
            }
            for(int i=col-2-cnt; i>=cnt; i--) {
                res.push_back(matrix[row-cnt-1][i]);
            }
            for(int i=row-cnt-2; i>cnt; i--) {
                res.push_back(matrix[i][cnt]);
            }
            cnt++;
        }
        return res;
        
    }
};