
/*
2016/04/24
Leetcode: palindrome partitioning ii
https://leetcode.com/problems/palindrome-partitioning-ii/
*/

// solution :dp
    int minCut(string s) {
        // do we need this deadly?
        // exception handler
        
        int sz = s.length();
        if(sz == 0) {
            return 0;
        } 
        // dp[i][j]: s[i-j] is palindrome
        vector<vector<bool> > dp = vector<vector<bool> >(sz, vector<bool>(sz, false));
        // fill in dp
        // length == 1
        for(int i=0; i<sz; i++) {
            dp[i][i] = true;
        }
        // length == 2
        for(int i=0; i<sz-1; i++) {
            dp[i][i+1] = (s[i] == s[i+1]);
        }
        
        // length >= 3
        for(int len = 2; len < sz; len++) {
            for(int i=0; i+len < sz; i++) {
                dp[i][i+len] = (dp[i+1][i+len-1] && s[i] == s[i+len]);
            }
        }
        
        
        //dp find min cut logic
        // res[i]: how many cuts for s[:i-1]; (length i)
        vector<int> res(sz+1, INT_MAX);
        res[0] = 0;
        // 
        for(int i=1; i<=sz; i++) {
            for(int j=0; j<i; j++) {
                // the back part
                if(dp[j][i-1]) {
                    res[i] = min(res[i], 1+res[j]);
                }
            }
        }
        return res[sz]-1;
    }
// solution: back tracking + cache
// dont know how

// solution: back tracking
// TLE
class Solution {
public:

    bool isPalindrome(string s) {
        int i=0, j=s.length()-1;
        while(i < j) {
            if(s[i++] != s[j--]) {
                return false;
            }
        }
        return true;
    }
    int minCut(string s) {
        int res = INT_MAX;
        int part = 0;
        if(isPalindrome(s)) {
            return 0;
        }
        minCut(s, res, part);
        return res;
    }
    
    void minCut(string s, int& res, int& part) {
        if(s.length() == 0) {
            res = min(res, part-1);
        }
        else {
            for(int i=1; i<=s.length(); i++) {
                string tmp = s.substr(0, i);
                if(isPalindrome(tmp)) {
                    part++;
                    minCut(s.substr(i), res, part);
                    part--;
                }
            }
        }
    }
};