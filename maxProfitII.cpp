
/*
LintCode: best time to buy and sell stock ii
http://www.lintcode.com/zh-cn/problem/best-time-to-buy-and-sell-stock-ii/
*/

// greedy
// find whatever larger than the previous one,
// add it up
class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        // write your code here
        int diff;
        int profit = 0;
        if(prices.size() == 0) {
            return profit;
        }
        for(int i=0; i<prices.size()-1; i++) {
            diff = prices[i+1]-prices[i];
            if(diff > 0) {
                profit += diff;
            }
        } 
        return profit;
    }
};