// Basic Calculator
// implement a basic calculator to evaluate a simple expression string

int calculate(string s){
	stack<int> stk;

	for(int i=0; i < s.length(); i++) {
		if(s[i] == '(') {
			stk.push_back('(');
		}
		if(s[i] == ' ') {
			continue;
		}
		if(s[i] != '-' && s[i] != '+') {
			continue;
		}

	}

}