

/*
LeetCode: longest Palindrome
https://leetcode.com/problems/longest-palindrome/
*/

class Solution {
public:
    
    int longestPalindrome(string s) {
       unordered_map<char, int> counter;
       
       for(char c:s) {
           counter[c]++;
       }
       
       int res = 0;
       int odd = 0;
       for(auto &m:counter) {
           if((m.second & 1) == 0) {
               res += m.second;
           }
           else {
               odd = 1;
               res += m.second-1;
           }
       }
       if(odd) {
           res ++;
       }
       return res;
        
    }
};

int longestPalindrome(string s) {
    int odds = 0;
    for(char c = 'A'; c <= 'z'; c++) {
        odds += count(s.begin(), s.end(), c) & 1;
    }
    return s.size()-odds+(odds>0);
}