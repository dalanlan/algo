
/*
LintCode: restore ip address
http://www.lintcode.com/zh-cn/problem/restore-ip-addresses/
*/

class Solution {
public:
    /**
     * @param s the IP string
     * @return All possible valid IP addresses
     */
     
    void helper(vector<string> &res, string s, string path) {
        int len = s.length();
        if(len == 0) {
            int count = 0;
            for(int i=0; i<path.length(); i++) {
                if(path[i] == '.') {
                    count++;
                }
            }
            if(count == 3) {
                res.push_back(path);
            }
            return;
        }
        
        string tmp;
        tmp = s.substr(0,1);
        string orig = path;
        if(stoi(tmp) >= 0 && stoi(tmp) < 256) {
            if(path.empty()) {
                path += tmp;
            }
            else {
                path += "."+tmp;
            }
            helper(res, s.substr(1, len-1), path);
            path = orig;
        }
        
        if(len>=2 && s[0] != '0') {
            tmp = s.substr(0,2);
            
            if(stoi(tmp) >= 0 && stoi(tmp) < 256) {
                if(path.empty()) {
                    path += tmp;
                }
                else {
                    path += "." + tmp;
                }
                helper(res, s.substr(2, len-2), path);
                path = orig;
            }
        }
        if(len >= 3 && s[0] != '0') {
             tmp = s.substr(0,3);
             if(stoi(tmp) >= 0 && stoi(tmp) < 256) {
                 if(path.empty()) {
                     path += tmp;
                 }
                 else {
                     path += "." + tmp;
                 }
                 helper(res, s.substr(3, len-3), path);
                 path = orig;
             }
        }
        
    }
    vector<string> restoreIpAddresses(string& s) { 
        vector<string> res;
        if(s.length() == 0) {
            return res;
        }
        string path;
        helper(res, s, path);
        return res;
        
    }
};