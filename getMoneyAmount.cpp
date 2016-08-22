
/*
Leetcode: guess number higher or lower ii
https://leetcode.com/problems/guess-number-higher-or-lower-ii/
*/

class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp= vector<vector<int>>(n+1, vector<int>(n+1, 0));
        return getMoneyAmount(dp, 1, n);
    }
    int getMoneyAmount(vector<vector<int>> &dp, int s, int e) {
        if(s >= e) {
            return 0;
        }
        
        if(dp[s][e] != 0) {
            return dp[s][e];
        }
        int res = INT_MAX;
        for(int i=s; i<=e; i++) {
            int tmp = i + max(getMoneyAmount(dp, s, i-1), getMoneyAmount(dp, i+1, e));
            res = min(res, tmp);
        }
        dp[s][e] = res;
        return res;
    }
};