
/*
Leetcode: Longest valid parentheses
https://leetcode.com/problems/longest-valid-parentheses/
*/

int longestValidParentheseslongestValidParentheses(string s) {
	stack<int> stk;
	for(int i=0; i<s.size(); i++) {
		if(s[i] == '(') {
			stk.push(i);
		}
		else {
			if(!stk.empty() && s[stk.top()] == '(') {
				stk.pop();
			}
			else {
				stk.push(i);
			}
		}
	}
	int res = 0;
	int last = s.size();
	if(stk.empty()) {
		return last;
	}
	int cut = 0;
	while(!stk.empty()) {
		cut = stk.top();
		stk.pop();
		res = max(res, last - cut - 1);
		last = cut;
	}
	res = max(res, cut);
	return res;
}