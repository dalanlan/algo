
/*
Leetcode: shortest palindrome
https://leetcode.com/problems/shortest-palindrome/
*/

// solution 1
class Solution {
public:
    string shortestPalindrome(string s) {
        string ss = s;
        reverse(s.begin(), s.end());
        int len = s.length();
        int i=len;
        for(;i>=0;i--) {
            if(ss.substr(0, i) == s.substr(len-i)) {
                break;
            }
        }
        return s.substr(0, len-i) + ss;
    }
};

// solution 2 KMP based solution
