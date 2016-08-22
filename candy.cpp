
/*
Leetcode: Candy
https://leetcode.com/problems/candy/
*/

class Solution {
public:
    int candy(vector<int>& ratings) {
        int sz = ratings.size();
        vector<int> dp(sz, 1);
        
        for(int i=1; i<sz; i++) {
            if(ratings[i] > ratings[i-1]) {
                dp[i] = max(dp[i-1]+1, dp[i]);
            }
        }
        for(int i=sz-2; i>=0; i--) {
            if(ratings[i] > ratings[i+1]) {
                dp[i] = max(dp[i], dp[i+1]+1);
            }
        }
        int sum = 0;
        for(int i=0; i<sz; i++) {
            sum += dp[i];
            
        }
        return sum;
    }
};