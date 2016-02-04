
/*
LintCode: simplify path
http://www.lintcode.com/zh-cn/problem/simplify-path/
*/

class Solution {
public:
    /**
     * @param path the original path
     * @return the simplified path
     */
    vector<string> split(string path, char del) {
        vector<string> res;
        stringstream ss(path);
        string tok;
        while(getline(ss, tok, del)) {
            res.push_back(tok);
        }
        return res;
        
    }
    string simplifyPath(string& path) {
        // Write your code here
        
        vector<string> res = split(path, '/');
       
        deque<string> stk;
        for(int i=0; i<res.size(); i++) {
            if(res[i] == "." || res[i] =="" ) {
                continue;
            }
            else if(res[i] == "..") {
                if(!stk.empty()) {
                    stk.pop_back();
                }
            }
            else {
                stk.push_back(res[i]);
            }
        }
        string ans;
        while(!stk.empty()) {
            ans += "/" + stk.front();
            stk.pop_front();
        }
        if(ans == ""){
            ans = "/";
        }
        return ans;
    }
};