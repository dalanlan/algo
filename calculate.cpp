// 224. Basic Calculator
// implement a basic calculator to evaluate a simple expression string

// Solution 1: stack 
int calculate(string s) {
	stack<int> nums, op;

	int res = 0;
	int sign = 1;
	int num = 0;

	for(char c:s) {
		if(isdigit(c)) {
			num = num*10 + c - '0';
		}
		else {
			res += num * sign;
			num = 0;
			if(c == '+') {
				sign = 1;
			}
			if(c == '-') {
				sign = -1;
			}
			if(c == ' ') {
				continue;
			}
			if(c == '(') {
				nums.push(res);
				op.push(sign);
				res = 0;
				sign = 1;
			}
			if(c == ')' && op.size() > 0) {
				res = op.top()*res + nums.top(); 
				nums.pop();
				op.pop();
			}
		}
	}

	res += num*sign;
	return res;
}

// Solution 2: recursive

int calculate(string s) {
	int pos = 0;
	return calc(s, pos);
}

int calc(string& s, int& i) {
	int res = 0;
	int sign = 1; // positive
	
	while( i < s.size() && s[i] != ')') {
		if(s[i] == '+' || s[i] == ' ') {
		    i++;
		}
		else if(s[i] == '-') {
			sign = -1;
			i++;
		}
		else if(s[i] == '(') {
			i++;
			res += sign * calc(s, i);
			sign = 1;
		}
		else { // numeric
			int num = 0;
			while(i<s.size() && isdigit(s[i])) {
				num = num*10 + s[i] - '0';
				i++;
			}
			res += sign*num; 
			sign = 1;
		}
	

	}
	i++;
	return res; 
}    