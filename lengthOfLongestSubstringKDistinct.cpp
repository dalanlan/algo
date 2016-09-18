
/*
LeetCode: longest substring with at most k distinct characters

*/

// solution 1:
int lengthOfLongestSubstringKDistinct(string s, int k) {
	int hashMap[256] = {0};
	int start = 0;
	int res = 0;
	int counter = 0;
	for(int i=0; i<s.size(); i++) {
		if(hashMap[s[i]] == 0) {
			counter++;
		}
		hashMap[s[i]]++;
		while(counter > k) {
			if(hashMap[s[start]] == 1) {
				counter--;
			}
			hashMap[s[start]]--;
			++start;
		}
		res = max(res, i-start+1);
	}
	return res;
}


// solution 2: index

int lengthOfLongestSubstringKDistinct(stirng s, int k) {
	unordered_map<char, int> mp;
	int start = 0;
	int res = 0;

	for(int i=0; i<s.size(); i++) {
		m[s[i]] = i;
		while(m.size() > k) {
			if(m[s[start]] == start) {
				m.erase(s[start]);
			}
			start++;
		}
		res = max(res, i-start+1);
	}
	return res;
}