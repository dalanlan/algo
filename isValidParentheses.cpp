/*
LintCode 423: Is valid bracket sequences
*/


/**
 * @param s A string
 * @return whether the string is a valid parentheses
 */
bool isValidParentheses(string& s) {
    // Write your code here
    stack<char> stk;
    char tmp;
    for(char c:s) {
        if(c == '(' || c == '{' || c == '[') {
            stk.push(c);
        }
        else {
            if(stk.empty()) {
                return false;
            }
            tmp = stk.top();
            if(c == ')' && tmp != '(') {
                return false;
            }
            if(c == ']' && tmp != '[') {
                return false;
            }
            if(c == '}' && tmp != '{') {
                return false;
            }
            stk.pop();
        }
        
    }
    return stk.empty();
}