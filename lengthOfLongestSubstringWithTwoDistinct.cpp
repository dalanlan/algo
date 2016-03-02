
/*
LeetCode: longest substring with at most two distinct characters

locked-down-problem
describtion:
Given a string S, find the length of the longest 
substring T that contains at most two distinct characters.
For example, Given S = “eceba”,
T is “ece” which its length is 3.

*/

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