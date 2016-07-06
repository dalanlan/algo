
/*
Leetcode: Evalute Reverse Polish Notation
https://leetcode.com/problems/evaluate-reverse-polish-notation/

*/

class Solution {
public:
    int calculate(int num1, int num2, string op) {
        if(op == "+") {
            return num1+num2;
        }
        if(op == "-") {
            return num1-num2;
        }
        if(op == "*") {
            return num1*num2;
        }
        if(op == "/") {
            return num1/num2;
        }
        return 0;
    }
    
    bool isOp(string ch) {
        return ch == "+" || ch == "-" || ch == "*" || ch == "/"; 
    }
    
    int evalRPN(vector<string>& tokens) {
        stack<int> num;
        for(int i=0; i<tokens.size(); i++) {
            if(!isOp(tokens[i])) {
                num.push(stoi(tokens[i]));
            }
            else {
                int num2 = num.top();
                num.pop();
                int num1 = num.top();
                num.pop();
                num.push(calculate(num1, num2, tokens[i]));
            }
        }
        return num.top();
    }
};