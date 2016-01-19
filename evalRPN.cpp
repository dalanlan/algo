
/*

LeetCode 150 : Evaluate Reverse Polish Notation

Evaluate the value of an arithmetic expression in Reverse Polish Notation.
Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Example:
["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6

*/


bool isOps(string s) {
    return (s=="+" || s== "-" || s=="*" || s== "/");
}
    int evalRPN(vector<string>& tokens) {
        stack<int> mid;
        for(int i=0; i<tokens.size(); i++) {
            if(!isOps(tokens[i])) {
                mid.push(stoi(tokens[i]));
            }
            else {
                int num1 = mid.top();
                mid.pop();
                int num2 = mid.top();
                mid.pop();
                int res = calc(num2, num1, tokens[i]);
                mid.push(res);
            }
        }
        return mid.top();
}

int calc(int num1, int num2, string op) {
	if(op == "+")
			return num1+num2;
    if(op == "-")
			return num1-num2;
	if(op == "*")
			return num1*num2;
	if(op == "/")
			return num1/num2;
}