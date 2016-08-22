
/*
LeetCode: Palindrome Partitioning II
https://leetcode.com/problems/palindrome-partitioning-ii/
*/

int minCut(string s) {
	int sz = s.size();
	vector<vector<bool>> dp(sz, vector<bool>(sz, false));

	// dp[i][j]
	for(int i=sz-1; i>=0; i--) {
		for(int j=i; j<sz; j++) {
			if((j -i <= 1 || dp[i+1][j-1])&& s[i] == s[j]) {
				dp[i][j] = true;
			}
		}
	}
	vector<int> cut(sz+1, INT_MAX);
	cut[0] = 0;
	for(int i=1; i<=sz; i++) {
		for(int j=0; j<i; j++) {
			if(dp[j][i-1]) {
				cut[i] = min(cut[i], 1+cut[j]);
			}
		}
	}
	return cut[sz]-1;
}