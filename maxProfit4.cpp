
/*
LeetCode: best time to buy and sell stock IV
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

Say you have an array for which the ith element is the price of a given stock on day i.
Design an algorithm to find the maximum profit. You may complete at most k transactions.
*/

int maxProfit(int k, vector<int>& prices) {
	
	// if k is extremely large, so that we can 
	// complete whatever transactions we wanna do
	
	int sz = prices.size();
	if(k >= sz-1) {
		return greedy(prices);
	}

	vector<vector<int>> global(k+1, vector<int>(sz, 0));
	vector<vector<int>> local(k+1, vector<int>(sz, 0));

	for(int i=1; i<=k; i++) {
		for(int j=1; j < sz; j++) {
			int diff = prices[j] - prices[j-1];
			local[i][j] = max(global[i-1][j-1] + max(0, diff), local[i][j-1] + diff);
			global[i][j] = max(global[i][j-1], local[i][j]);
		}
	}
	return global[k][sz-1];

}

int greedy(vector<int>& prices) {
	int profit = 0;
	int diff = 0;
	for(int i=1; i<prices.size(); i++) {
		diff = prices[i] - prices[i-1];
		if(diff > 0) {
			profit += diff;
		}
	}
	return profit;
}