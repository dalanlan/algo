
/*
LeetCode: remove invalid parentheses
https://leetcode.com/problems/remove-invalid-parentheses/
*/


vector<string> removeInvalidParentheses(string s) {
	queue<string> que;
	unordered_set<string> visited;

	que.push(s);
	visited.insert(s);

	bool found = false;
	vector<string> res;

	while(!que.empty()) {
		string tmp = que.front();
		que.pop();

		if(isValid(tmp)) {
			found = true;
			res.push_back(tmp);
		}

		if(found) {
			continue;
		}
		for(int i=0; i<tmp.size(); i++) {
			if(tmp[i] != '(' && tmp[i] != ')') {
				continue;
			}
			string cur = tmp.substr(0, i) + tmp.substr(i+1);
			if(visited.count(cur) == 0) {
				que.push(cur);
				visited.insert(cur);
			}
			
 		}
	}
	return res;
}

bool isValid(string s) {
	int cnt = 0;
	for(int i=0; i<s.size(); i++) {
		if(s[i] != '(' && s[i] != ')') {
			continue;
		}
		else if(s[i] == '(') {
			cnt++;
		}
		else if(cnt-- == 0) {
			return false;
		}

	}
	return cnt==0;
}