
/*
LintCode: best time to buy and sell stock iii
http://www.lintcode.com/zh-cn/problem/best-time-to-buy-and-sell-stock-iii/
*/

/*
It's similar to find out the two subarrays whose sum max
*/

class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
int maxProfit(vector<int> &prices) {

	int sz = prices.size();
	if(sz == 0) {
		return 0;
	}

	//dp: from left to right
	int minPrice = prices[0];
	vector<int> left(sz, 0);
	for(int i=1; i<sz; i++) {
		minPrice = min(minPrice, prices[i]);
		left[i] = max(left[i-1], prices[i]-minPrice);
 	}

 	//dp: from right to left
 	int maxPrice = prices[sz-1];
 	vector<int> right(sz, 0);
 	for(int i=sz-2; i>=0; i--) {
 		maxPrice = max(maxPrice, prices[i]);
 		right[i] = max(right[i+1], maxPrice-prices[i]);
 	} 

 	// we can buy and sell stock on the same day
 	int profit = 0;
 	for(int i=0; i<sz-1; i++) {
 		profit = max(profit, left[i]+right[i]);
 	}
 	return profit;
 	}
};