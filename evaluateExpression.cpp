
/*
LintCode: expression evaluation
http://www.lintcode.com/zh-cn/problem/expression-evaluation/
*/


// solution 1: caution the priority

class Solution {
public:
    /**
     * @param expression: a vector of strings;
     * @return: an integer
     */
    
    int cal(int num1, int num2, string s) {
        if(s == "+") {
            return num1+num2;
        }
        if(s == "-") {
            return num1-num2;
        }
        if(s == "*") {
            return num1*num2;
        }
        if(s == "/") {
            return num1/num2;
        }
    }
    
    int evaluateExpression(vector<string> &expression) {
        // write your code here
        if(expression.size() == 0) {
            return 0;
        }
        
        stack<int> num;
        stack<string> op;
        
        for(int i=0; i<expression.size(); i++) {
            string cur = expression[i];
            if(cur == "(") {
                op.push(cur);
                
            }
            else if(cur == ")") {
                while(!op.empty() && op.top() != "(") {
                    int num2 = num.top();
                    num.pop();
                    int num1 = num.top();
                    num.pop();
                    
                    int res = cal(num1, num2, op.top());
                    num.push(res);
                    op.pop();
                }
                
                op.pop();
               
            }
            else if(cur == "+" || cur == "-") {
                if(op.empty() || !op.empty() && op.top() == "(") {
                    op.push(cur);
                }
                else {
                    // while *, /
                    // pop
                    while(!op.empty() && op.top() != "(") {
                        int num2 = num.top();
                        num.pop();
                        int num1 = num.top();
                        num.pop();
                        
                        int res = cal(num1, num2, op.top());
                        num.push(res);
                        op.pop();
                    }
                    op.push(cur);
                }
            }
            else if(cur == "*" || cur == "/") {
                if(op.empty() || !op.empty() && op.top() == "(") {
                    op.push(cur);
                }
                else {
                    while(!op.empty() && (op.top() != "+" && op.top() != "-" && op.top() != "(")) {
                            int num2 = num.top();
                            num.pop();
                            int num1 = num.top();
                            num.pop();
                            
                            int res = cal(num1, num2, op.top());
                            num.push(res);
                            op.pop();
                        }
                        op.push(cur);
                }
            }
            else {
                num.push(stoi(cur));
            }
        }
        
        while(!op.empty()) {
            int num2 = num.top();
            num.pop();
            int num1 = num.top();
            num.pop();
            int res = cal(num1, num2, op.top());
            num.push(res);
            op.pop();
        }
        return num.top();
    }
};