
/*
LintCode: anagrams
http://www.lintcode.com/zh-cn/problem/anagrams/
*/


class Solution {
public:    
    /**
     * @param strs: A list of strings
     * @return: A list of strings
     */
    
// solution 1: This solution is not so very elegant
// cause it uses the whole string as the key of the map
vector<string> anagrams(vector<string> &strs) {
	unordered_map<string, vector<string>> myMap;
	for(int i=0; i<strs.size(); i++) {
		string tmp(strs[i]);
		sort(strs[i].begin(), strs[i].end());
		if(myMap.find(strs[i]) != myMap.end()) {
			myMap[strs[i]].push_back(tmp);
		}
		else {
			vector<string> mySet{tmp};
			myMap[strs[i]] = mySet;
		}
	}
	
	vector<string> res;
	for(auto &x:myMap) {
		if(x.second.size() > 1) {
			for(auto &y:x.second) {
				res.push_back(y);
			}
		}
	}
	return res;
}
};
