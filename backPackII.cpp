
/*
LintCode: back pack ii
http://www.lintcode.com/zh-cn/problem/backpack-ii/
*/

class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A & V: Given n items with size A[i] and value V[i]
     * @return: The maximum value
     */
    int backPackII(int m, vector<int> A, vector<int> V) {
        // write your code here
        
        // dp[i][j] 
        int sz = A.size();
        vector<vector<int> > dp = vector<vector<int> >(sz+1, vector<int>(m+1, 0));
        
        for(int i=1; i<=sz; i++) {
            for(int j=0; j<=m; j++) {
                dp[i][j] = max(dp[i-1][j], j>=A[i-1]?dp[i-1][j-A[i-1]]+V[i-1]:0);
            }
        }
        return dp[sz][m];
    }
};