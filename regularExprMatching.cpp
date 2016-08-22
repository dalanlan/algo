
/*
Leetcode: Regular expression matching
https://leetcode.com/problems/regular-expression-matching/
*/

bool isMatch(string s, string p) {
	// judging with the length of p
	if(p.empty()) {
		return s.empty();
	}

	if(p.size() == 1) {
		return s.size() == 1 && (s[0] == p[0] || p[0] == '.');
	}
	if(p[1] == '*') {
		return isMatch(s, p.substr(2)) || !s.empty() && (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p);
	}
	else {
		return !s.empty() && (s[0] == p[0] || p[0] == '.' ) && isMatch(s.substr(1), p.substr(1));
	}
}


bool isMatch(string s, string p) {
	int sLen = s.size();
	int pLen = p.size();

	vector<vector<bool>> dp(sLen+1, vector<bool>(pLen+1, false));
	dp[0][0] = true;

	// corner case
	for(int i=2; i<=pLen; i+=2) {
	    dp[0][i] = dp[0][i-2] && p[i-1] == '*';
	    if(!dp[0][i]) {
	        break;
	    }
	}
	for(int i=1; i<=sLen; i++) {
		for(int j=1; j<=pLen; j++) {
			if(j>=2 && p[j-1] == '*') {
				dp[i][j] = dp[i][j-2] || (s[i-1] == p[j-2] || p[j-2] == '.' ) && dp[i-1][j];
			}
			else {
				dp[i][j] = dp[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '.');
			}
		}
	}
	return dp[sLen][pLen];
}