
/*
LintCode: spiral matrix ii
http://www.lintcode.com/en/problem/spiral-matrix-ii/
*/

class Solution {
public:
    /**
     * @param n an integer
     * @return a square matrix
     */
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res=vector<vector<int>>(n, vector<int>(n,0));
        
        int count = 0;
        int val = 1;
        while(count*2 < n) {
            for(int i=count; i<n-count; i++) {
                res[count][i]=val++;
            }            
            for(int i=count+1; i<n-count; i++) {
                res[i][n-count-1]=val++;
            }
            if(n-count*2 == 1) {
                break;
            }
            for(int i=n-count-2; i>=count; i--) {
                res[n-count-1][i]=val++;
            }
            for(int i=n-count-2; i>=count+1; i--) {
                res[i][count]=val++;
            }
            count++;
        }
        return res;
    }
};