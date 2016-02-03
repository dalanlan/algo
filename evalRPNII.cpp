
/*
LintCode : evaluate reverse polish notation
http://www.lintcode.com/zh-cn/problem/evaluate-reverse-polish-notation/
*/
class Solution {
public:
    /**
     * @param tokens The Reverse Polish Notation
     * @return the value
     */
    bool isOps(string s) {
        return (s=="+" ||s=="-" ||s=="*" ||s=="/");
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        for(int i=0; i<tokens.size(); i++) {
            if(!isOps(tokens[i])) {
                nums.push(stoi(tokens[i]));
            }
            else {
                int num2 = nums.top();
                nums.pop();
                int num1 = nums.top();
                nums.pop();
                int res;
                if(tokens[i] == "+") {    
                    res = num1 + num2;
                }
                else if(tokens[i] =="-") {
                    res = num1 - num2;
                }
                else if(tokens[i] =="*") {
                    res = num1 * num2;
                }
                else if(tokens[i] == "/") {
                    res = num1/num2;
                }
                nums.push(res);
            }
        }
        return nums.top();
    }
};