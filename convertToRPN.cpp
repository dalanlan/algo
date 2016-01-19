
/*
Lintcode 370: Convert expression to Reverse Polish Notation(RPN)
*/


/**
 * @param expression: A string array
 * @return: The Reverse Polish notation of this expression
 */


// What matters is the algorithm

bool isOps(string s) {
	return (s == "+" || s== "-" || s=="*" || s=="/" || s=="(" || s==")");
}

int convertStringToInt(string s) {
	if(s == "+" || s == "-") {
		return 1;
	}
	if(s == "*" || s == "/") {
		return 2;
	}
}
int compare(string op1, string op2) {
	int a = convertStringToInt(op1);
	int b = convertStringToInt(op2);
	if(a > b) {
		return 1;
	}
	if(a == b) {
		return 0;
	}
	if(a < b) {
		return -1;
	}
	
}
vector<string> convertToRPN(vector<string> &expression) {
	
	stack<string> op;
	stack<string> res;

	for(int i=0;i<expression.size();i++) {
		// number
		if(!isOps(expression[i])) {
			res.push(expression[i]);
		}
		// ops
		else {
			if(expression[i] == "(") {
				op.push(expression[i]);
			}
			else if(expression[i] == ")") {
				while(!op.empty() && op.top() != "(") {
					res.push(op.top());
					op.pop();
				}
				//deprecate "("
				op.pop();
			}
			//"+","-","*","/"
			else {
				if(!op.empty() && op.top() == "(" || op.empty()) {
					op.push(expression[i]);
				}
				else {
					while(!op.empty() && compare(op.top(), expression[i])>=0) {
						res.push(op.top());
						op.pop();
					}
					op.push(expression[i]);
				}
			}
		}
	}	
	while(!op.empty()) {
		res.push(op.top());
		op.pop();
	}

	vector<string> ans;
	while(!res.empty()) {
		ans.insert(ans.begin(), res.top());
		res.pop();
	}
	return ans;

}