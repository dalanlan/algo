/*
LeetCode: 
126. word ladder ii
https://leetcode.com/problems/word-ladder-ii/
*/

vector<vector<string>> findLadders(string start, string end, unordered_set<string>& wordList) {
	vector<vector<string>> res;

	unordered_set<string> cur;
	unordered_set<string> next;
	unordered_set<string> vis;

	bool found = false;
	unordered_map<string, vector<string>> father;

	cur.insert(start);

	while(!found && !cur.empty()) {
		for(auto &x:cur) {
			vis.insert(x);
		}

		for(auto &x:cur) {
			string tmp = x;
			
			for(int i=0; i<tmp.size(); i++) {
				for(char c = 'a'; c <= 'z'; c++) {
					if(c == tmp[i]) {
						continue;
					}
					tmp[i] = c;
					if(tmp == end) {
						found = true;
					}
					if(wordList.count(tmp) && !vis.count(tmp)) {
						next.insert(tmp);
						father[x].push_back(tmp);
					}
				}
				tmp[i] = x[i];
			}
		}
		cur = next;
		next.clear();
	}

	vector<string> path;
	backTrace(res, path, father, start, end);
	return res;
	
}

void backTrace(vector<vector<string>> &res, vector<string> &path, unordered_map<string, vector<string>> &father, string cur, string end) {
	path.push_back(cur);
	if(cur == end) {
		res.push_back(path);
	}
	else {
		for(auto x:father[cur]) {
			backTrace(res, path, father, x, end);
		}
	}
	path.pop_back();
}