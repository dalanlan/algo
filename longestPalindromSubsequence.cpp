
/* 
Geeks for geeks : longest palindromic subsequence

Given a sequence, find the length of the longest palindromic subsequence in it. For example, if the given sequence is “BBABCBCAB”, then the output should be 7 as “BABCBAB” is the longest palindromic subseuqnce in it. “BBBBB” and “BBCBB” are also palindromic subsequences of the given sequence, but not the longest ones.

http://www.geeksforgeeks.org/dynamic-programming-set-12-longest-palindromic-subsequence/

*/

int longestPalindromSubsequence(string &s) {
	int len = s.length();
	if(len <= 1) {
		return len;
	}

	// dp[i][j]~ longest subsequence from i to j
	vector<vector<int>> dp<len, vector<int>(len, 0);

	for(int i=0; i<len; i++) {
		dp[i][i] = 1;
	}
	int count = 1;


	for(int j=0; j<len; j++) {
		for(int i=0; i<j; i++) {
			if(s[i] != s[j]) {
				dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
			}
			else {
				if(j==i+1) dp[i][j]=2;
				else {
					dp[i][j] = dp[i+1][j-1] + 2;
				}
			}
			count = max(count, dp[i][j]);
		}
	}
	return count;
}