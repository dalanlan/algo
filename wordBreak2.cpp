
/*
LeetCode: work break
https://leetcode.com/problems/word-break/

Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".
*/

// solution 1: back tracking
// TLE
bool wordBreak(string s, unordered_set<string>& wordDict) {
	return wordBreak(s, 0, wordDict);
}
bool wordBreak(string s, int index, unordered_set<string>& wordDict) {
	if(index == s.length()) {
		return true;
	}
	// i: end position
	for(int i=index; i<s.length(); i++) {
		string tmp = s.substr(index, i-index+1);
		if(wordDict.count(tmp)) {
			if(wordBreak(s, i+1, wordDict)) {
				return true;
			}
		}
	}
	return false;
}

// solution 2: WA
// Wrong DP

int countMaxLength(unordered_set<string>& wordDict) {
	int res = 0;
	for(auto d:wordDict) {
		res = max(res, d.size());
	}
	return res;
}

bool wordBreak(string s, unordered_set<string>& wordDict) {
	if(wordDict.count(s) || s.length() == 0) {
		return true;
	}

	int maxLen = countMaxLength(wordDict);

	// init
	vector<bool> dp(s.length()+1, false);
	dp[0] = true;

	for(int i=1; i<=s.length(); i++) {
		// j is the length of the chunk
		// WROOOONG!!!!
		for(int j=1; j<=maxLen && i+j <= s.length(); j++) {
			string tmp = s.substr(i, j);
			if(dp[i-1] && wordDict.count(tmp)) {
				dp[i+j] = true;
			}
		}
	}
	return dp[s.length()];

}


// solution 3: 
// Try DP again

bool wordBreak(string s, unordered_set<string>& wordDict) {
	if(wordDict.count(s) || s.length() == 0) {
		return true;
	}

	int maxLen = countMaxLength(wordDict);

	// init
	vector<bool> dp(s.length()+1, false);
	dp[0] = true;
	
	for(int i=1; i<=s.length(); i++) {
		// j: length
		for(int j=0; j<=i && j<=maxLen; j++) {
			if(dp[i-j] && wordDict.count(s.substr(i-j, j))) {
				dp[i] = true;
				// control loop
				break;
			}
		}
	}
	return dp[s.length()];
}