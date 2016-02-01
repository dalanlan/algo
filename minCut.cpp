
/*
LintCode: palindrome partition ii
http://www.lintcode.com/zh-cn/problem/palindrome-partitioning-ii/
*/

// solution 1: based on palindrome partition 
// TLE
class Solution {
public:
    /**
     * @param s a string
     * @return an integer
     */
    
    void partition(string s, int& ans, int start, vector<string>& path) {
        
        for(int i=start; i<s.length(); i++) {
            if(isPalindrome(s, start, i)) {
                path.push_back(s.substr(start, i-start+1));
                if(i == s.length()-1) {
                    ans = min(ans, (int)path.size());
                }
                else {
                    partition(s, ans, i+1, path);
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
    int minCut(string s) {

        if(isPalindrome(s, 0, s.length()-1)) {
            return 0;
        }
        int ans = INT_MAX;
        vector<string> path;
        partition(s, ans, 0, path);
        return ans-1;
    }
};



// solution 2:
class Solution {
public:
    /**
     * @param s a string
     * @return an integer
     */
     
    void palin(string s, vector<vector<bool>> &palindrome) {
        int len = palindrome.size();
        for(int i=0; i<len; i++) {
            palindrome[i][i] = true;
        }
        for(int i=0; i<len-1; i++) {
            palindrome[i][i+1] = (s[i] == s[i+1]);
        }
        
        for(int length = 2; length < len; length++) {
            for(int start = 0; start+length<len; start++) {
                palindrome[start][start+length] = (palindrome[start+1][start+length-1] && s[start] == s[start+length]); 
            }
        }
        
    }
    
    int minCut(string s) {
        if(s.length() == 0) {
            return 0;
        }
        
        vector<vector<bool>> palindrome(s.length(), vector<bool>(s.length(), false));
        palin(s, palindrome);
        
        vector<int> f(s.length()+1, INT_MAX);
        f[0]=0;
        for(int i=1; i<=s.length(); i++) {
            for(int j=0; j<i; j++) {
                if(palindrome[j][i-1]) {
                    f[i] = min(f[i], f[j]+1);
                }
            }
        }
        return f[s.length()]-1;
        
    }