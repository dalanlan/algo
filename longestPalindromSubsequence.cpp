
/* 
Geeks for geeks : longest palindromic subsequence

Given a sequence, find the length of the longest palindromic subsequence in it. For example, 
if the given sequence is “BBABCBCAB”, then the output should be 7 
as “BABCBAB” is the longest palindromic subseuqnce in it. “BBBBB” and “BBCBB” are also 
palindromic subsequences of the given sequence, but not the longest ones.

http://www.geeksforgeeks.org/dynamic-programming-set-12-longest-palindromic-subsequence/

*/

int longestPalindromSubsequence(string &s) {
	int len = s.length();
	int i, j, k;

	// dp[i][j]~ longest subsequence from i to j
	vector<vector<int>> dp=vector<vector<int>>(len, vector<int>(len, 0));

	for(i = 0; i<len; i++) {
		dp[i][i] = 1;
	}
	// we must iterator from length
	for(k = 2; k <=len; i++) {
		for(i=0; i<len-k+1; i++) {
			j = i+k-1;
			if(s[i] == s[j] && k == 2) {
				s[i][j]=2;
			}
			else  if(s[i] == s[j]) {
				s[i][j] = s[i+1][j-1] + 2;
			}	
			else {
				s[i][j] = max(s[i+1][j], s[i][j-1]);
			}
		}
	}
	return dp[0][len-1];
}
