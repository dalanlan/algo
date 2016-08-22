
/*
LeetCode: Palindrome Pairs
https://leetcode.com/problems/palindrome-pairs/
*/

    bool isPalindrome(string s) {
	int lo = 0, hi = s.size()-1;
	while(lo < hi) {
		if(s[lo++] != s[hi--]) {
			return false;
		}
	}
	return true;
}

vector<vector<int>> palindromePairs(vector<string>& words) {
	vector<vector<int>> res;

	unordered_map<string, int> map;
	for(int i=0; i<words.size(); i++) {
		string tmp(words[i]);
		reverse(tmp.begin(), tmp.end());
		map[tmp] = i;
	}

	if(map.count("")) {
		int pos = map[""];
		for(int i=0; i<words.size(); i++) {
			if(words[i] != "" && isPalindrome(words[i])) {
				res.push_back({pos, i});
			}
		}
	}

	for(int i=0; i<words.size(); i++) {
		string cur = words[i];
		for(int j=0; j<cur.size(); j++) {
			string left = cur.substr(0, j);
			// right cannot be ""
			// so we need to adjust from // the very  beginning
			string right = cur.substr(j);
			if(map.count(left) != 0 && isPalindrome(right) && map[left] != i) {
				res.push_back({i, map[left]});
			}
			if(map.count(right) != 0 && isPalindrome(left) && map[right] != i) {
				res.push_back({map[right], i});
			}
		}
	}
	return res;
}