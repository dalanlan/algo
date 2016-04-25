

/*
LeetCode: best time to buy and sell stock iv
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
*/

/*
The idea behind is really interesting.
Clean dp though.

dp[i][j] indicates the max profit we can get with i transaction on j days


dp[i][j] 	= max(dp[i][j-1], max(prices[j]- prices[jj] + dp[i-1][jj]))
	= max(dp[i][j-1], prices[j] + max(dp[i-1][jj] - prices[jj]));
*/

class Solution {
public:
    
int maxProfit(int k, vector<int>& prices) {
	
	// corner cases: when k is extremely large
	// we can conduct as many transaction as 
	// we want
	int sz = prices.size();
	if(sz == 0) {
		return 0;
	}
	if(k >= sz-1) {
		return greedy(prices);
	}

	vector<vector<int>> dp = vector<vector<int>> (k+1, vector<int>(sz, 0));

	
	for(int i=1; i<=k; i++) {
		// initialization
	    int localMax = dp[i-1][0] - prices[0];
		for(int j=1; j<sz; j++) {
			dp[i][j] = max(dp[i][j-1], prices[j] + localMax);
			localMax = max(localMax, dp[i-1][j]-prices[j]);
		}
	}
	return dp[k][sz-1];

}

int greedy(vector<int>& prices) {
	int res = 0;
	for(int i=1;i<prices.size(); i++) {
		int diff  = prices[i]-prices[i-1];
		if(diff > 0) {
			res+= diff;
		}
	}
	return res;
}
};