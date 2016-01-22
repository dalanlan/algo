

/*
LintCode : Longest Common subsequence
http://www.lintcode.com/zh-cn/problem/longest-common-subsequence/

*/


class Solution {
public:
    /**
     * @param A, B: Two strings.
     * @return: The length of longest common subsequence of A and B.
     */
    int longestCommonSubsequence(string A, string B) {
        int m = A.length();
        int n = B.length();
        
        int dp[m+1][n+1];
        for(int i=0; i<=m; i++) {
            dp[i][0] = 0;
        }
        for(int j=0; j<=n; j++) {
            dp[0][j] = 0;
        }
        for(int i=1; i<=m; i++) {
            for(int j=1; j<=n; j++) {
                if(A[i-1] == B[j-1]) {
                    dp[i][j] = dp[i-1][j-1]+1;
                }
                else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
};
