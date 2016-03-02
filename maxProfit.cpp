
/*
LintCode: best time to buy and sell stock
http://www.lintcode.com/en/problem/best-time-to-buy-and-sell-stock/
*/


// solution 1: TLE
class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        // write your code here
        int sz = prices.size();
        if(sz == 0) {
            return 0;
        }
        //the max profit sell on day i 
        vector<int> dp(sz, 0);
        int res = INT_MIN;
        
        for(int i=1; i<sz; i++) {
            for(int j=0; j<i; j++) {
                dp[i] = max(dp[i], prices[i]-prices[j]);
                res = max(res, dp[i]);
            }
        }
        return res;
    }
};

// solution 2: very basic idea

int maxProfit(vector<int> &prices) {
	int sz = prices.size();
	int minPrice = INT_MAX;
	int profit = INT_MIN;
	for(int i=0; i<sz; i++) {
		minPrice = min(minPrice, prices[i]);
		profit = max(profit, prices[i]-minPrice);
	}
	return profit>0?profit:0;
}