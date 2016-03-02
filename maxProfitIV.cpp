
/*
LintCode: best time to buy and sell stock iv
http://www.lintcode.com/zh-cn/problem/best-time-to-buy-and-sell-stock-iv/
*/

// more space complexity
class Solution {
public:
    /**
     * @param k: An integer
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(int k, vector<int> &prices) {
        // write your code here
        
        int sz = prices.size();
        if(sz == 0) {
            return 0;
        }
        if(k >= sz) {
            return maxSolve(prices);
        }
        vector<vector<int> > localMax=vector<vector<int> >(sz, vector<int>(k+1, 0));
        vector<vector<int> > globalMax=vector<vector<int> >(sz, vector<int>(k+1, 0));
    
        int diff;
        for(int i=1; i<sz; i++) {
            diff=prices[i]-prices[i-1];
            for(int j=1; j<=k; j++) {
                localMax[i][j] = max(globalMax[i-1][j-1] + diff, localMax[i-1][j] + diff);
                globalMax[i][j] = max(globalMax[i-1][j], localMax[i][j]);
            }
        }
        return globalMax[sz-1][k];
    }
    
    // trick: when k is large then prices.size()
    // it can be computed more easily
    int maxSolve(vector<int> &prices) {
        
        int res=0;
        int diff;
        for(int i=1; i<prices.size(); i++) {
            diff = prices[i]-prices[i-1];
            if(diff>0) {
                res += diff;
            }
            
        }
        return res;
    }
};