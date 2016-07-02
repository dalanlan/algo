
/*
LeetCode: decode ways
https://leetcode.com/problems/decode-ways/
*/


int numDecodings(string s) {
	int len = s.size();
	if(len == 0) {
		return 0;
	}

	vector<int> dp(len+1, 0);

	dp[0] = 1;
	dp[1] = s[0]=='0'?0:1;

	for(int i=2; i<=len; i++) {
		dp[i] = s[i-1] == '0'?0:dp[i-1];
		if(s[i-2] == '1' || (s[i-1] <= '6' && s[i-2] == '2')) {
			dp[i] += dp[i-2];
		}
	}
	return dp[len];
}