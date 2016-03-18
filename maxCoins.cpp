
/*
LeetCode: burst ballons
https://leetcode.com/problems/burst-balloons/

lintCode: burst ballons
http://www.lintcode.com/en/problem/burst-balloons/
*/

class Solution {
public:
    int maxCoins(vector<int>& nums) {
	int res = 0;
	int sz = nums.size();

	if(sz == 0) {
		return res;
	}

	vector<int> num(nums);
	num.insert(num.begin(), 1);
	num.push_back(1);
    
    int sz2 = sz+2;
	vector<vector<int>> dp(sz2, vector<int>(sz2, 0));
    
    for(int k=2; k<sz2; k++) {
        for(int l=0; l<sz2-k; l++) {
            int r=l+k;
            for(int i=l+1; i<r;i++) {
                dp[l][r] = max(dp[l][r], dp[l][i] + dp[i][r] + num[l]*num[i]*num[r]);
            }
        }
    }
	return dp[0][sz+1];

}
};