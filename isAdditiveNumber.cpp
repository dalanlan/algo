// Additive Number

/* Additive number is a string whose digits can form additive sequence.
A valid additive sequence should contain at least three numbers.
Except for the first two numbers, each subsequent number must be 
the sum of the preceding two.
*/

/*
bool isAdditiveNumber(string num) {
	for(int i=0; i < num.length()-2; i++) {
		// 112358 
		// 1+1=2, 1+2=3, 2+3=5, 3+5=8
		// only test previous mentioned situation
		if((num[i]-'0') + (num[i+1]-'0') != (num[i+2] - '0')) {
			return false;
		}
	}
	return true;	
}
*/

// solution 1:dfs 
bool isAdditiveNumber(string num) {
	int len = num.length();
	if(len == 0) {
		return true;
	}

	// i stands for the length of num1 
	for(int i=1; i <= (len-1)/2; i++) {
		
		// num1 cannot start with '0' while it's not 0
		// num1: [0,i-1]
		if(num[0] == '0' && i >= 2) {
			continue;
		}

		// j stands for the length of num2 
		// num2: [i,i+j-1]
		// max(i,j) <= (len-1)/2
		for(int j=1; max(i,j) <= (len - 1)/2; j++) {
			if(num[i] == '0' && j >= 2) {
				continue;
			}
			long num1 = stol(num.substr(0, i));
			long num2 = stol(num.substr(i, j));

			string substr = num.substr(i+j);
			if(isAdditive(substr, num1, num2)) {
				return true;
			}
		}

	}
	return false;
}

bool isAdditive(string num, long num1, long num2) {
	if(num.length() == 0) {
		return true;
	}
	long sum = num1 + num2;
	string s = to_string(sum);
	if(num.substr(0, s.length()) != s) {
		return false;
	}
	return isAdditive(num.substr(s.length()), num2, sum);
}


// solution 2: dfs
// refactor 
bool isAdditiveNumber(string num) {
	// num1[0, i-1]
	// num2[i, i+j-1]
	// res[i+j, xxx]
	int len = num.length();
	for(int i=1; i<= (len-1)/2; i++) {
		for(int j=1; max(i,j) <= (len-1)/2; j++) {
			if(dfs(num, 0, i, j)) {
				return true;
			}
		}
	}
	return false;
}

bool dfs(string num, int start, int len1, int len2) {
	if((num[start] == '0' && len1 >= 2) || (num[start+len1] == '0' && len2 >= 2)) {
		return false;
	}

	long num1 = stol(num.substr(start, len1));
	long num2 = stol(num.substr(start+len1, len2));
	string res = to_string(num1+num2);
	
	if(num.substr(start+len1+len2).length() == 0) {
		return true;
	}
	if(num.substr(start+len1+len2).substr(0, res.length()) != res) {
		return false;
	}
	return dfs(num, start+len1, len2, res.length());

}