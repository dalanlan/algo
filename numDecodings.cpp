// Decode Ways

/* A message containing letters from A-Z is being
encoded to numbers using the following mapping:
'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine
total number of ways to decode it.
*/

// dynamic programming

int numDecodings(string s) {
	int len = s.length();
	if(len == 0) {
		return 0;
	}

	//res[n] responsonds to s with n length, so we should return res[n]
	int *res = new int[len+1];
	//vector<int> res(len+1);
	res[0] =1; 

	if(s[0] == '0') {
		res[1] = 0;
	}
	else {
		res[1] = 1;
	}

	for(int i=2; i<= len; i++) {
		if(s[i-1] == '0') { // the last char of string s, or the current char 
			res[i] = 0;
		}
		else {
			res[i] = res[i-1];
		}

		if(s[i-2] == '1' || (s[i-2] == '2' && s[i-1] <= '6')) {
			res[i] += res[i-2];
		}
	}

	return res[len];

}
