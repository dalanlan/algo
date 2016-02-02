
/*
LintCode: work break
http://www.lintcode.com/zh-cn/problem/word-break/
*/

// solution 1: WA
// runtime error
// unacceptable recursive depth
class Solution {
public:
    /**
     * @param s: A string s
     * @param dict: A dictionary of words dict
     */
     
    // bool helper(string s, unordered_set<string> &dict, int maxLen, int start) {
    //     if(start == s.length()) {
    //         return true;
    //     }
    //     for(int i=start; i<s.length(); i++) {
    //         if(i-start+1 <=maxLen && dict.find(s.substr(start, i-start+1)) != dict.end() && helper(s, dict, maxLen, i+1)) {
    //             return true;
    //         }
    //     }
    //     return false;
    // }
    // int countMaxLen(unordered_set<string> &dict) {
    //     int  count = 0;
    //     for(auto &x:dict) {
    //         count = max(count, (int)x.size());
    //     }
    //     return count;
    // }
    // bool wordBreak(string s, unordered_set<string> &dict) {
    //     // write your code here
    //     int maxLen = countMaxLen(dict);
    //     return helper(s, dict, maxLen, 0);
        
    // }
    
    // solution 2:AC
    // dp
    int countMaxLen(unordered_set<string> &dict) {
        int count = 0;
        for(auto &d:dict) {
            count = max(count, (int)d.size());
        }
        return count;
    }
    bool wordBreak(string s, unordered_set<string> &dict) {
        if(dict.find(s) != dict.end() || s.length() == 0) {
            return true;
        }
        
        int maxLen = countMaxLen(dict);
        int len = s.length();
        vector<bool> canBreak(len+1, false);
        canBreak[0] = true;
        for(int i=1; i<=len; i++) {
            for(int j=0; j<=i && j<=maxLen; j++) {
                if(canBreak[i-j] && dict.find(s.substr(i-j, j)) != dict.end()) {
                    canBreak[i] = true;
                    break;
                }
            }
        }
        return canBreak[len];
        
    }
};