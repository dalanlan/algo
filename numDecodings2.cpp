
/*
LintCode: decode ways
http://www.lintcode.com/zh-cn/problem/decode-ways/
*/

// dynamic programming
// tricks: dp[0] = 0; or you will suffer since index >= 2

class Solution {
public:
    /**
     * @param s a string,  encoded message
     * @return an integer, the number of ways decoding
     */
    int numDecodings(string& s) {
        // Write your code here
        
        int len = s.length();
        if(len == 0) {
            return 0;
        }
        vector<int> dp(len+1, 0);
        dp[0] = 1;
        dp[1] = s[0] == '0'?0:1;
        for(int i=2; i<=len; i++) {
            // current char:s[i-1]
            if(s[i-1] != '0') {
                dp[i] += dp[i-1];
            }    
            if(s[i-2] == '1' || s[i-2] == '2' && s[i-1] <='6') {
                dp[i] += dp[i-2];
            } 
        }
        
        return dp[len];
    }
};