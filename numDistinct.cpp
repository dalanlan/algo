
/*
Lintcode: distinct subsequences
http://www.lintcode.com/zh-cn/problem/distinct-subsequences/
*/


// solution 1: DP
//http://leetcodesolution.blogspot.com/2013/09/distinct-subsequences.html 

class Solution {
public:    
    /**
     * @param S, T: Two string.
     * @return: Count the number of distinct subsequences
     */
    int numDistinct(string &S, string &T) {
        // write your code here
        int sLen = S.length();
        int tLen = T.length();
        vector<vector<int>> dp = vector<vector<int>>(sLen+1, vector<int>(tLen+1, 0));
        
        for(int i=sLen; i>=0; i--) {
            for(int j=tLen; j>=0; j--) {
                if(j == tLen) {
                    dp[i][j] = 1;
                }
                else if(i == sLen) {
                    dp[i][j] = 0;
                }
                else if(S[i] == T[j]) {
                    dp[i][j] = dp[i+1][j+1] + dp[i+1][j];
                }
                else {
                    dp[i][j] = dp[i+1][j];
                }
            }
        }
        
        
        return dp[0][0];
    }
};


// solution 2: another DP
//https://lefttree.gitbooks.io/leetcode/content/dynamicProgramming2/distinctSubsequences.html
int numDistinct(string &S, string &T) { 
        
        int sLen = S.length();
        int tLen = T.length();
        
        vector<vector<int> >dp = vector<vector<int>>(sLen+1, vector<int>(tLen+1, 0));
        dp[0][0] = 1;
        
        for(int i=1; i<= sLen; i++) {
            dp[i][0] = 1;
        }
        
        for(int i=1; i<=sLen; i++) {
            for(int j=1; j<=tLen; j++) {
                dp[i][j] = dp[i-1][j];
                if(S[i-1] == T[j-1]) {
                    dp[i][j] += dp[i-1][j-1];
                }
            }
        }
        return dp[sLen][tLen];
    

    }

   

   // solution 3:
        int numDistinct(string &S, string &T) {
        int sLen = S.length();
        int tLen = T.length();
        if(tLen == 0) {
            return 1;
        }
        if(sLen == 0) {
            return 0;
        }
        vector<int> dp = vector<int>(tLen, 0);
        for(int i=0; i<sLen; i++) {
            for(int j=tLen-1; j>=0; j--) {
                if(T[j] == S[i]) {
                    dp[j] += (j>0?dp[j-1]:1);
                }
            }
        }
        return dp[tLen-1];
    }