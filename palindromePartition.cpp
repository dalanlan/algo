
/*
LintCode:palindrome partition 
http://www.lintcode.com/zh-cn/problem/palindrome-partitioning/
*/
class Solution {
public:
    /**
     * @param s: A string
     * @return: A list of lists of string
     */

   //actually we don't need param `end`
    void partition(vector<vector<string>> &res, string s,vector<string> &path, int start, int end) {

            for(int j=start; j<end; j++) {
                if(isPalindrome(s, start, j)) {
                    path.push_back(s.substr(start, j-start+1));
                    if(j == s.length()-1) {
                        res.push_back(path);
                    }
                    else {
                        partition(res, s, path, j+1, s.length());
                    }
                    path.pop_back();
                }
            }
        
        
    }
    bool isPalindrome(string s, int lo, int hi) {
        while(lo < hi) {
            if(s[lo] != s[hi]) {
                return false;
            }
            lo++;
            hi--;
        }
        return true;
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        if(s.length() == 0) {
            return res;
        }
        vector<string> path;
        partition(res, s, path, 0, s.length());
        return res;
    }
};