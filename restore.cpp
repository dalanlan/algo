
/*

Leetcode: restore ip addresses
https://leetcode.com/problems/restore-ip-addresses/

Given a string containing only digits, restore it by 
returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)

*/

class Solution {
public:

    void restore(vector<string> &res, string path, string &s, int index, int dot) {
        if(index == s.length() ) {
            if(dot == 3) {
                res.push_back(path);
            }
        }
        else {
            for(int i=index; i<index+4 && i< s.length(); i++) {
                if(i != index && s[index] == '0') {
                    break;
                }
                if(dot > 3) {
                    break;
                }
                string ss = s.substr(index, i-index+1);
                int tmp = stoi(ss);
                if(tmp >=256) {
                    break;
                }
                if(path.empty()) {
                    restore(res, ss, s, i+1, dot);
                }
                else {
                    restore(res, path+"."+ss, s, i+1, dot+1);
                }
                
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        if(s.empty()) {
            return {};
        }
        vector<string> res;
        restore(res, "", s, 0, 0);
        
        return res;
        
    }
};