
/*
LintCode: restore ip address
http://www.lintcode.com/zh-cn/problem/restore-ip-addresses/
*/

// A cleaner solution
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        int len = s.size();
        
        for(int i=1; i<4 && i<len-2; i++) {
            for(int j=i+1; j<i+4 && j < len-1; j++) {
                for(int k=j+1; k<j+4 && k < len; k++) {
                    string s1 = s.substr(0, i);
                    string s2 = s.substr(i, j-i);
                    string s3 = s.substr(j, k-j);
                    string s4 = s.substr(k);
                   
                    if(isValid(s1) && isValid(s2) && isValid(s3) && isValid(s4)) {
                        res.push_back(s1 + "." + s2 + "." + s3 + "." + s4);
                    }
                }
            }
        }
        return res;
        
    }
    
    bool isValid(string s) {
        if(s.length() > 3 || s.length() == 0 || s[0] == '0' && s.length() > 1 || stoi(s) > 255) {
            return false;
        }
        return true;
    }
}; 


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