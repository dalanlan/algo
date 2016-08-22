
/*
Leetcode: Palindrome permutation II
*/

vector<string> generatePalindromes(string s) {
	vector<string> res;
	unordered_map<char,int> count;

	for(char c: s) {
		count[c]++;
	}

	int odd = 0; 
	char mid;
	string half;

	for(auto p:count) {
		if(p.second & 1) {
			if(odd > 0) {
				return res;
			}
			mid = p.first;

		}
		half += string (p.second, p.first);
	}

	res = permute(half);
	for(string &p:permutation) {
		string t(p);
		reverse(t.begin(), t.end());
		if(odd) {
			t = mid + t;
		}
		p += t; // reference instead of copy of value
	}
	return res;


}

vector<string> permute(string s) {
	vector<string> res;
	string t(s);
	do {
		res.push_back(s);
		next_permutation(s.begin(), s.end());
	} while(s!= t);
	
	return res;
}