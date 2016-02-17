
/*
Lintcode: reverse words in a string 
http://www.lintcode.com/zh-cn/problem/reverse-words-in-a-string/
*/


class Solution {
public:
    /**
     * @param s : A string
     * @return : A string
     */
    stack<string> split(string s, char del) {
        stack<string> res;
        string tok;
        stringstream ss(s);
        while(getline(ss, tok, del)) {
            res.push(tok);
        }
        return res;
    }
    string reverseWords(string s) {
        // write your code here
        stack<string> res = split(s, ' ');
        
        string ans;
        
        while(!res.empty()) {
            string tmp = res.top();
            res.pop();
            if(tmp == " ") {
                continue;
            }
            else {
                if(ans.empty()) {
                    ans += tmp;
                }
                else {
                    ans += " "+tmp;
                }
            }
        }
        return ans;
    }
};