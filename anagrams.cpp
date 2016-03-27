
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


// solution 2: use a hash function to deal with the key 
// of the hash map

int getHash(vector<int> count) {
	int hash = 0;
	int a= 378551;
	int b=63689;

	for(int i=0; i<count.size(); i++) {
		hash = hash * a+ count[i];
		a = a * b;
	}
	return hash;
}
vector<string> anagrams(vector<string> &strs) {
	unordered_map<int, vector<string> > myMap;
	for(int i=0; i<strs.size(); i++) {
		vector<int> count = vector<int>(26, 0);
		for(char c : strs[i]) {
			count[c-'a'] ++;
		}
		int hash = getHash(count);
		if(myMap.find(hash) != myMap.end()) {
			myMap[hash].push_back(strs[i]);
		}
		else {
			vector<string> tmp {strs[i]};
			myMap[hash] = tmp;
		}
	}
	vector<string> res;
	for(auto &m : myMap) {
		if(m.second.size() > 1) {
			for(auto &y:m.second) {
				res.push_back(y);
			}
		}
	}
	return res;
}