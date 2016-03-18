
/*
LeetCode: best time to buy and sell stock
https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1) {
            return 0;
        }
        int minPrices = prices[0];
        int res = INT_MIN;
        for(int i=1; i<prices.size(); i++) {
            res = max(prices[i]-minPrices, res);
            minPrices = min(minPrices, prices[i]);
        
        }
        return res>0?res:0;
    }
};


/*
LeetCode: best time to buy and sell stock ii
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
greedy 
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for(int i=1; i<prices.size(); i++) {
            if(prices[i]-prices[i-1] > 0) {
                profit += prices[i]-prices[i-1];
            }
        }
        return profit;
    }
};