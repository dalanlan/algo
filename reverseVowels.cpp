
/*
Leetcode: reverse vowels of a string
https://leetcode.com/problems/reverse-vowels-of-a-string/
*/



class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<char> set ({'a','e','i','o','u','A','E','I','O','U'});
        
        int i=0, j=s.length()-1;
        while(i<j) {
            while(i<j && (set.count(s[i]) == 0)) {
                i++;
            }
            while(i<j && (set.count(s[j]) == 0)) {
                j--;
            }
            if(i<j) {
                swap(s[i], s[j]);
                i++;
                j--;
            }
            
        }
        return s;
    }
};