
/*
LeetCode: longest substring with at most two distinct characters

locked-down-problem
describtion:
Given a string S, find the length of the longest 
substring T that contains at most two distinct characters.
For example, Given S = “eceba”,
T is “ece” which its length is 3.

*/

// solution 1: use hash map to project the number of the characters showing up
int lengthOfLongestSubstringWithTwoDistinct(string s) {
	
	int maxLen=INT_MIN;
	if(s.length() == 0) {
		return maxLen;
	}

	int start = 0, end = 0;
	int len = 0;
	int counter = 0;
	int hashMap[256]={0};

	while(end < s.length()) {
		if(hashMap[s[end]]==0) {
			counter++;
		}
		hashMap[s[end]]++;
		end++;

		while(counter > 2) {
			if(hashMap[s[start]] == 1) {
				counter--;
			}
			hashMap[s[start]]--;
			start++;
		}
		maxLen = max(maxLen, end-start);

	}
	return maxLen;

}


// solution 2: use hash map to project the number of 
// characters' indexes
int lengthOfLongestSubstringTwoDistinct(string s) {
	unordered_map<char, int> mp;
	int left = 0;
	int res = 0;

	for(int i=0; i<s.size(); i++) {
		mp[s[i]] = i;
		while(mp.size() > 2) {
			if(mp[s[left]] == left) {
				mp.erase(s[left]);
			}
			left++;
		} 
		res= max (res, i-left+1);
	}
	return res;
}