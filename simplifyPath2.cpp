
/*
LeetCode: simplify path
https://leetcode.com/problems/simplify-path/

Given an absolute path for a file(Unix-style), simplify it.
*/

vector<string> split(string path, char del) {
	vector<string> res;
	stringstream ss(path);
	string token;

	while(getline(ss, token, del)) {
		res.push_back(token);
	}
	return res;
}

string simplifyPath
(string path) {
	vector<string> pathSet = split(path, '/');

	vector<string> ans;
	for(string s: pathSet) {
		if(s == "." || s == "") {
			continue;
		}
		else if(s == "..") {
			if(!ans.empty()) {
				ans.pop_back();
			}
		}
		else {
			ans.push_back(s);
		}
	}
	
	if(ans.empty()) {
		return "/";
	}
	string res = "";
	for(string s: ans) {
		res += "/" + s;
	}
	return res;
}