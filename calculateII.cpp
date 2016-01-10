// 227. Basic Calculator II

/*
Implement a basic calculator to evaluate a
simple expression string.
The expression string contains only non-negative integers,
`+`/`-`/`*`/`/` operators and empty spaces ` `.
The integer division should truncate zero.
*/

int calculate(string s) {
	stack<int> num;

	char sign = '+';
	int tmp = 0;
	int res = 0;

	for(int i=0; i<s.length(); i++) {
		if(isdigit(s[i])) {
			tmp = tmp*10 + s[i] - '0';
		}
		if(!isdigit(s[i]) && !isspace(s[i]) || i == s.length()-1) {
			if(sign == '+') {
				num.push(tmp);
			} 
			else if(sign == '-') {
				num.push(-tmp);
			}
			else if(sign == '*') {
				int ns = tmp*num.top();
				num.pop();
				num.push(ns);
			}
			else {
				int ns = num.top()/tmp;
				num.pop();
				num.push(ns);
			}
			sign = s[i];
			tmp = 0;
		}


	}
	while(!num.empty()) {
		res+=num.top();
		num.pop();
	}
	return res;
}