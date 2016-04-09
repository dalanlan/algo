
/*
LeetCode: longest valid parentheses
https://leetcode.com/problems/longest-valid-parentheses/
*/


// WA: wrong understanding
// a well-formed parenthese pair doesn't mean we must
// have continous '(' and ')'
// meaning they are not interruptted
class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> dp(s.length()+1, 0);
        int res = 0;
        for(int i=2; i<=s.length(); i++) {
            dp[i] = res;
            if(s[i-1] == ')' && s[i-2] == '(') {
                dp[i] = max(dp[i], dp[i-2]+2);
                res = max(dp[i], res);
            }
          
        }
      
        return dp[s.length()];
        
    }
};


// WA: wrong understanding again
// longest means substring, not subsequence
// this solution is cute though
    int longestValidParentheses(string s) {
        int len = s.length();
        vector<int> dp(len+1, 0);
        
        int left = 0;
        int right = 0;
        for(int i=1; i<=len; i++) {
            dp[i] = dp[i-1];
            if(s[i-1] == '(') {
                left++;
            }
            // right pathese
            else if(left > right) {
                right++;
                
                dp[i] += 2;
            }
            
        }
        return dp[len];
    }