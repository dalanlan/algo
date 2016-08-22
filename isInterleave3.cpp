
/*
Leetcode: interleaving string 
https://leetcode.com/problems/interleaving-string/
*/

// recursive solution
class Solution {
public:
    unordered_set<string> cache;
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.empty() && s2.empty() && s3.empty()) {
            return true;
        }
        if(cache.count(s1+"#"+s2) || s1.size() + s2.size() != s3.size()) {
            return false;
        }
        if(!s1.empty() && !s3.empty() && s1[0]==s3[0]) {
            if(isInterleave(s1.substr(1), s2, s3.substr(1))) {
                return true;
            } 
        }
        if(!s2.empty() && !s3.empty() && s2[0] == s3[0]) {
            if(isInterleave(s1, s2.substr(1), s3.substr(1))) {
                return true;
            }
        }
        
        cache.insert(s1+"#"+s2);
        return false;
    }
};


// dp solution
  bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.size();
        int len2 = s2.size();
        int len3 = s3.size();
        
        if(len1 + len2 != len3) {
            return false;
        }
        
        vector<vector<bool>> dp(len1+1, vector<bool>(len2+1, false));
        dp[0][0] = true;
        
        for(int i=1; i<=len1; i++) {
            dp[i][0] = dp[i-1][0] && s1[i-1] == s3[i-1];
        }
        for(int j=1; j<=len2; j++) {
            dp[0][j] = dp[0][j-1] && s2[j-1] == s3[j-1];
        }
        
        for(int i=1; i<=len1; i++) {
            for(int j=1; j<=len2; j++) {
                dp[i][j] = dp[i-1][j] && s1[i-1] == s3[i+j-1] || dp[i][j-1] && s2[j-1] == s3[i+j-1];
            }
        }
        
        return dp[len1][len2];
    }