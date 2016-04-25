
/*
LeetCode: roman to integer

*/
class Solution {
public:
  
    int romanToInt(string s) {
	if(s.length() == 0) {
		return 0;
	}
	int len = s.length();
	unordered_map<char, int> map;
	map['I'] = 1;
	map['V'] = 5;
	map['X'] = 10;
	map['L'] = 50;
	map['C'] = 100;
	map['D'] = 500;
	map['M'] = 1000;

	int res = map[s[len-1]];
	int pivot = res;
	for(int i=len-2; i>=0; i--) {
		int cur = map[s[i]];
		if(cur >= pivot) {
			res += cur;
		}
		else {
			res -= cur;
		}
		pivot = cur;
	}
	return res;
}

};