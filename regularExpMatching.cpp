
/*
LintCode: regular expression matching
https://leetcode.com/problems/regular-expression-matching/
*/


// solution 1: recursive
// AC
bool isMatch(string s, string p) {
	if(p.empty()) {
		return s.empty();
	}

	if(p.length() == 1) {
		return s.length() == 1 && (s[0] == p[0] || p[0] == '.');
	}

	if(p[1] == '*') {
		// could match multiple last word
		return (isMatch(s, p.substr(2)) || (!s.empty() && (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p)));
	}
	else {
		return (!s.empty() && (s[0] == p[0] || p[0] == '.' ) && isMatch(s.substr(1), p.substr(1)));
	}
}


// solution 2: dp
class Solution {
public:
    /**
     * @param s: A string 
     * @param p: A string includes "." and "*"
     * @return: A boolean
     */
    bool isMatch(const char *s, const char *p) {
        // write your code here
        
        int sLen = strlen(s);
        int pLen = strlen(p);
        
        vector<vector<bool>> dp = vector<vector<bool>>(sLen+1, vector<bool>(pLen+1, false));
        
        dp[0][0] = true;
        
        // dp[0][j]
        for(int j=2; j<=pLen; j+=2) {
            if(p[j-1] == '*') {
                dp[0][j] = true;
            } 
            if(!dp[0][j]) {
                break;
            }
        }
        // dp[i][0] 
        
        for(int i=1; i<=sLen; i++) {
            for(int j=1; j<=pLen; j++) {
                if(p[j-1] == '*' && j >= 2) {
                    dp[i][j] = dp[i][j-2] ||  (s[i-1] == p[j-2] || p[j-2] == '.') && dp[i-1][j];
                }
                else {
                    dp[i][j] = dp[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '.');
                    
                }
            }
        }
        return dp[sLen][pLen];
    }
};