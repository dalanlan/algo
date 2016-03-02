
/*
LeetCode: longest substring without repeating characters
https://leetcode.com/problems/longest-substring-without-repeating-characters/
*/

// solution 1: my idea
// take care of the initialization
int lengthOfLongestSubstring(string s) {
	if(s.length() <= 1) {
		return s.length();
	}

	int maxLen = INT_MIN;
	int start=0;
	int hashmap[256];
	for(int i=0; i<255; i++) {
	    hashmap[i] = -1;
	}
	int i;
	for(i=0; i<s.length(); i++) {
		if(hashmap[s[i]] != -1) {
		
			maxLen = max(maxLen, i-start);
			int tmp=hashmap[s[i]]+1;
			for(int j=start; j<=hashmap[s[i]]; j++) {
				hashmap[s[j]] = -1;
			}
			start = tmp;
	
		}
		hashmap[s[i]] = i;
	}
	
	maxLen = max(maxLen, i-start);
	return maxLen;
}


// solution 2: use template

int lengthOfLongestSubstring(string s) {
	int hashmap[256]={0};
	int len = s.length();
	if(len <= 1) {
	    return len;
	}
	int counter=0;
	int start = 0, end = 0;
	
    int maxLen = INT_MIN;
	while(end < len) {
		if(hashmap[s[end]]>0) {
			counter++;
		}
		hashmap[s[end]]++;
		end++;

		while(counter > 0) {
			if(hashmap[s[start]] > 1) {
				counter--;
			}
			hashmap[s[start]]--;
			start++;

		}
		maxLen = max(maxLen, end-start);
	}
	return maxLen;

}