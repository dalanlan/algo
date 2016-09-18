
/*
Leetcode: word break ii

*/

// solution 1:
// https://leetcode.com/discuss/33884/11ms-c-solution-concise

unordered_map<string, vector<string>> map;

vector<string> combine(string word, vector<string> res) {
	for(int i=0; i<res.size(); i++) {
		res[i] += " "+word;
	}
	return res;
}
vector<string> wordBreak(string s, unordered_set<string>& dict) {
	if(map.count(s)) {
		return map[s];
	}
	vector<string> res;

	if(dict.count(s)) {
		res.push_back(s);
	}
	for(int i=1; i<s.size(); i++) {
		string tmp = s.substr(i);
		if(dict.count(tmp)) {
			string rem = s.substr(0, i);
			vector<string> prev = combine(tmp, wordBreak(rem, dict));
			res.insert(res.end(), prev.begin(), prev.end());
		}
	}
	map[s] = res;
	return res;
} 
unordered_map<string, vector<string>> map;
vector<string> combine(string word, vector<string> res) {
	vector<string> result;
	for(string s:res) {
		result.push_back(word + " " + s);
	}
	return result;
}
vector<string> wrodBreak(string s, unordered_set<string> dict) {
	

	if(map.count(s)) {
		return map[s];		
	}
	vector<string> res;
	if(dict.count(s)) {
		res.push_back(s);
	}

	for(int i=1; i<s.size(); i++) {
		string start = s.substr(0, i);
		if(dict.count(start)) {
			vector<string> rem = combine(start, wordBreak(s.substr(i));
			res.insert(res.back(), rem.begin(), rem.end());
		}
	}
	map[s] = res;
	return res;
}

// solution 2:
// back tracking
// TLE


// WA: to be fix
// correct the cache 
int countMaxLen(unordered_set<string>& wordDict) {
	int res = 0;
	
	for(auto d:wordDict) {
		res = max(res, (int)d.size());
	}
	return res;
}

vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
	
	// add up cache
	unordered_map<string, vector<string> > map;

	int maxLen = countMaxLen(wordDict);

	return wordBreak(s, wordDict, 0, maxLen, map);

}


vector<string> wordBreak(string path, string s, unordered_set<string>& wordDict, int index, int maxLen, unordered_map<string, vector<string> > &map) {
	vector<string> res; 

	if(index == s.length()) {
		return res;
	}
	
	// i: last bit of 
	for(int i=index; i<s.length() && i<maxLen+index; i++) {
		string tmp = s.substr(index, i-index+1);
		if(wordDict.count(tmp)) {
			if(map.count(tmp)) {
				return map[tmp];
			}
			else {

			}
			if(path.empty()) {
				wordBreak(res, tmp, s, wordDict, i+1, maxLen);
			}
			else {
			    wordBreak(res, path+" "+tmp, s, wordDict, i+1, maxLen);
			}
		}
	}
	map[s] = res;
	return res;
	
}