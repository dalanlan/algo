
/*
LeetCode: work break II

Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.

Return all such possible sentences.

For example, given
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].

A solution is ["cats and dog", "cat sand dog"].

*/

// solution 1: TLE
// I think it's right
int countMaxLen(unordered_set<string>& wordDict) {
	int res = 0;
	for(auto d:wordDict) {
		res = max(res, (int)d.size());
	}
	return res;
}

vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
	vector<string> res;
	int maxLen = countMaxLen(wordDict);

	wordBreak(res, "", s, wordDict, 0, maxLen);

	return res;
}


void wordBreak(vector<string>& res, string path, string s, unordered_set<string>& wordDict, int index, int maxLen) {
	
	if(index == s.length()) {
		res.push_back(path);
	}
	else {
		// i: last bit of 
		for(int i=index; i<s.length() && i<maxLen+index; i++) {
			string tmp = s.substr(index, i-index+1);
			if(wordDict.count(tmp)) {
				if(path.empty()) {
					wordBreak(res, tmp, s, wordDict, i+1, maxLen);
				}
				else {
				wordBreak(res, path+" "+tmp, s, wordDict, i+1, maxLen);
				}
				
			}
		}
	}
}

// solution 2: dp?
// WIP