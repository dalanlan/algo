
/*
LeetCode: Remove K th digits
https://leetcode.com/problems/remove-k-digits/
*/

class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k==num.size()) {
            return "0";
        }
        string res("");
        int sz = num.size()-k;
        
        for(int i=0; i<num.size(); i++) {
            while(k > 0 && !res.empty() && res.back() > num[i]) {
                k--;
                res.pop_back();
            }
            res.push_back(num[i]);
        }
        
       
        while( k > 0) {
            res.pop_back();
            k--;
        }
        int i = 0;
        while(i<res.size()) {
            if(res[i] == '0') {
                i++;
            }
            else {
                break;
            }
        }
        res = res.substr(i);
        
        if(res.empty()) {
            return "0";
        }
        return res;
    }
};
