
/*
LeetCode: longest substring with at least k repeating characters
https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/
*/

    int longestSubstring(string s, int k) {
	int i=0, sz = s.size();
	int res = 0;

	while(i + k < sz) {
		int max_idx =i; 
		vector<int> m(26, 0);
		int mask = 0;

		for(int j = i; j <sz; j++) {
			int t = s[j] - 'a';
			m[t]++;
			if(m[t] < k) {
				mask |= (1 << t);
			}
			else {
				mask &= (~(1 << t));
			}
			if(mask == 0) {
				res = max(res, j-i+1);
				max_idx = j;
			}
		}
		i = max_idx+1;
	}
	return res;
    }