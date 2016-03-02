
/*
LintCode: minmum window substring
http://www.lintcode.com/zh-cn/problem/minimum-window-substring/
*/


// solution 1: the idea is borrowed from 
// leetcode discussion, and i'll give you 
// that community of leetcode is much more
// powerful than that of lintcode
// link: https://leetcode.com/discuss/72701/here-10-line-template-that-can-solve-most-substring-problems

string minWindow(string &source, string &target) {
	int hashMap[256] = {0};
	for(char c:target) {
		hashMap[c]++;
	}
	int counter=target.length(), minWindow = INT_MAX, begin = 0, end = 0, head;

	while(end < source.length()) {
		if(hashMap[source[end]] > 0) {
			counter--;
		}
		hashMap[source[end]]--;
		end++;
		while(counter == 0) { // valid 
			if(end - begin < minWindow) {
				minWindow = end - begin;
				head = begin;
			}
			hashMap[source[begin]]++;
			if(hashMap[source[begin]] > 0) {
				counter++;
			} 
			begin++;
		}
		
	} 
	return minWindow == INT_MAX?"":source.substr(head, minWindow);

}

// solution 2: try another idea from discussion
// https://leetcode.com/discuss/78260/simple-c-solution-12ms

 string minWindow(string s, string t) {
	int hashMap[256] = {0};
	for(char c:t) {
		hashMap[c]++;
	}

	int len=0, validLen = 0, minLen=INT_MAX;
	int start = 0, minStart=INT_MAX;

	for(int i=0; i<s.length(); i++) {
		if(hashMap[s[i]] > 0) {
			validLen++;
		}	
		hashMap[s[i]]--;
		len++;

		while(hashMap[s[start]] < 0) {
			hashMap[s[start]]++;
			start++;
			len--;
		}
		if(validLen == t.length() && len < minLen) {
			minLen = len;
			minStart = start;
		}
	}
	
	return minLen == INT_MAX?"":s.substr(minStart, minLen);
}