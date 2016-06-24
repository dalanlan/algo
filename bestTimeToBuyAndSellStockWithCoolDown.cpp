
/*
LeetCode: best time to buy and sell stock with cooldown
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
*/

// https://leetcode.com/discuss/71354/share-my-thinking-process
int maxProfit(vector<int>& prices) {
    int prevBuy = INT_MIN, buy = INT_MIN, prevSell = 0, sell = 0, rest=0;
    for(int p:prices) {
        prevBuy = buy;
        buy = max(prevSell-p, prevBuy);
        prevSell = sell;
        sell = max(prevBuy+p, sell);
        rest = prevSell;
    }
    return sell;
}