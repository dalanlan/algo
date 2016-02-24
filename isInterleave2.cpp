
/*
LintCode: interleaving string
http://www.lintcode.com/zh-cn/problem/interleaving-string/
*/

class Solution {
public:
    /**
     * Determine whether s3 is formed by interleaving of s1 and s2.
     * @param s1, s2, s3: As description.
     * @return: true of false.
     */
    bool isInterleave(string s1, string s2, string s3) {
        // write your code here
        
        int len1 = s1.length();
        int len2 = s2.length();
    
        if(len1 == 0) {
            return s2 == s3;
        }
        if(len2 == 0) {
            return s1 == s3;
        }
        if(len1 + len2 != s3.length()) {
            return false;
        }
        vector<vector<bool> > dp = vector<vector<bool> >(len1+1, vector<bool>(len2+1, false));
        dp[0][0] = true;
        for(int i=1; i<=len2; i++) {
            dp[0][i] = dp[0][i-1] && s3[i-1] == s2[i-1];
        }
        
        for(int i=1; i<=len1; i++) {
            dp[i][0] = dp[i-1][0] && s3[i-1] == s1[i-1];
        }
        
        for(int i=1; i<=len1; i++) {
            for(int j=1; j<=len2; j++) {
                dp[i][j] = (dp[i-1][j] && s1[i-1] == s3[i+j-1]) || (dp[i][j-1] && s2[j-1]==s3[i+j-1]);
            }
        }
        
        return dp[len1][len2];
        
        
    }
};