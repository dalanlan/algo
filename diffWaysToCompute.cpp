// Different ways to add parenthese

// solution 1: dp
// compile error
vector<vector<vector<int> > > res;
vector<int> nums; 
vector<char> ops;
int len;

vector<int> diffWaysToCompute(string input) {
	if(input.length() == 0) {
		return vector<int>();
	}

	storeInfo(input);
	if(ops.size() == 0) {
		return nums;
	}

	len = nums.length();
	res = vector<vector<vector<int> > >(len, vector<vector<int> >());
	for(int i = 0; i < len; i++) {
		res[i] = vector<vector<int>>(len, vector<int>());
	}

	calc();
	return res[0][len-1];

}

void calc() {
	for(int dist = 0; dist < len; i++) {
		for(int i = 0; i < len - dist; i++) {
			if(dist == 0) {
				res[i][i+dist].push_back(nums[i]);
			}
			else {
				for(int j = 0; j < dist; j++){
					for(auto l: res[i][i+j]) {
						for(auto r:res[i+j+1][i+dist]) {
							if (ops[i+j] == '-') {
								res[i][i+dist].push_back(l-r);
							}
							else if(ops[i+j] == '+') {
								res[i][i+dist].push_back(l+r);
							}
							else if(ops[i+j] == '*'{
								res[i][i+dist].push_back(l*r);	
							}
						}
					}
				}

			}
		}
	}
}
void storeInfo(string input) {
	int cur = 0, pre = 0;

	while(cur < input.length()) {
		if(input[cur] == '-' || input[cur] == '*' || input[cur] == '+') {
			nums.push_back(stoi(input.substr(pre, cur-pre)));
			ops.push_back(input[cur]);
			pre = cur+1;
		}
		cur++;
	}
	nums.push_back(stoi(input.substr(pre, cur-pre)));
}


// sol2: recursive solution

vector<int> diffWaysToCompute(string input) {
	unordered_map<string, vector<int>> cache;
	return diffWaysToCompute(input, cache);
}

vector<int> diffWaysToCompute(string input, unordered_map<string, vector<int>>& cache) {
	if(cache.find(input) != cache.end()) {
		return cache[input];
	}

	vector<int> res;
	vector<int> left;
	vector<int> right;
	char ops;
	for(int i=0; i<input.length(); i++) {
		if(input[i] != '-' && input[i] != '+' && input[i] != '*') {
			continue;
		}

		ops = input[i];
		left = diffWaysToCompute(input.substr(0, i), cache);
		right = diffWaysToCompute(input.substr(i+1), cache);

		for(auto l:left) {
			for(auto r:right) {
				if(ops == '-') {
					res.push_back(l-r);
				}
				else if(ops == '+') {
					res.push_back(l+r);
				}
				else if(ops == '*') {
					res.push_back(l*r);
				}
			}
		}
		

	}
	if(res.size() == 0) {
		res.push_back(stoi(input));
	}
	//cache.insert(input, res);
	cache[input] = res;
	return res;
}