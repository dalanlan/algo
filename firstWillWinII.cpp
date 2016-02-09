
/*
LintCode: coins in a line ii
http://www.lintcode.com/zh-cn/problem/coins-in-a-line-ii/
*/

class Solution {
public:
    /**
     * @param values: a vector of integers
     * @return: a boolean which equals to true if the first player will win
     */
    // bool firstWillWin(vector<int> &values) {
    //     // write your code here
    // }
    bool firstWillWin(vector<int> &values) {
	int sz = values.size();
	if(sz <= 2) {
		return true;
	}
	vector<int> dp(sz, 0);
	dp[sz-1] = values[sz-1];
	dp[sz-2] = values[sz-1] + values[sz-2];
    
    int sum = values[sz-1]+values[sz-2];
	int value1, value2;
	for(int i=sz-3; i>=0; i--) {
	    sum += values[i];
		value1 = values[i] + min(dp[i+2], i<sz-3?dp[i+3]:0);
		value2 = values[i] + values[i+1] + min(i<sz-3?dp[i+3]:0, i<sz-4?dp[i+4]:0);
		dp[i] = max(value1, value2);
	}
    
	return dp[0]*2>sum;
}
};