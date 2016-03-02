
/*
LeetCode: substring with concatenation of all words
https://leetcode.com/problems/substring-with-concatenation-of-all-words/
*/


// solution 1: WA
// can pass basic test cases

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
	
	vector<int> res;
	if(s.length() == 0 || words.size() == 0) {
		return res;
	}
	int wordLen = words[0].length();

	unordered_map<string, int> hashmap;
	
	for(int i=0; i<words.size(); i++) {
		if(hashmap.count(words[i]) == 0) {
			hashmap[words[i]]=1;
		}
		else {
			hashmap[words[i]]++;
		}
	}
	
    unordered_map<string, int > oldMap(hashmap);
	int start=0, end=0;
	int counter=0;

	while(end < s.length()) {
		string cur = s.substr(end, wordLen);
		if(hashmap.count(cur) == 0) {
		    // unknown string
		    start = end + 1;
		    end = start;
		    counter = 0;
		    hashmap = oldMap;
		}
		else if(hashmap[cur] <= 0) {
		    // duplicates
            hashmap[s.substr(start, wordLen)]++;
            start = start + wordLen;
            counter--;
		}
		else {
		    hashmap[cur]--;
		    counter++;
		    end = end+wordLen;
	
		    while(counter == words.size()) {
			    res.push_back(start);
			    hashmap[s.substr(start,wordLen)]++;
			    cout<<hashmap[s.substr(start,wordLen)]<<endl;
			    start = start + wordLen;
			    cout<<"start:"<<start <<", end:"<<end<<endl;
			    counter--;
		    }
		}

	}
	return res;

}
};

// solution: AC

class Solution {
public:
    vector<int> findSubstring(string s, vector<string> &words) {
	vector<int> res;
	if(s.length() == 0 || words.size() == 0) {
		return res;
	}

	unordered_map<string, int> counts;
	for(string s: words) {
		counts[s]++;
	}

	int wordLen = words[0].length();
	int sz = words.size();
	int len = s.length();

	for(int i=0; i<len-wordLen*sz+1; i++) {
		unordered_map<string, int> seen;
		int j;
		for(j=0; j<sz; j++) {
			string cur = s.substr(i+j*wordLen, wordLen);
			if(counts.count(cur) == 0) {
				break;
			}
			else {
				seen[cur]++;
				if(seen[cur] > counts[cur]) {
					break;
				}
			}
		}

		if(j == sz) {
			res.push_back(i);
		}

	}
	return res;
}
};