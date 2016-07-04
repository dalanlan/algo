
/*
Leetcode: remove duplicate letters
https://leetcode.com/problems/remove-duplicate-letters/

Given a string which contains only lowercase letters, remove duplicate letters so that every letter appear once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.

Example:
Given "bcabc"
Return "abc"

Given "cbacdcbc"
Return "acdb"
*/

    string removeDuplicateLetters(string s) {
        vector<int> cnt(256, 0);
        string res = "0";
        for(char c:s) {
            cnt[c]++;
        }
       
        vector<bool> visited(256,false);
        for(char c:s) {
            --cnt[c];
            if(visited[c]) {
                continue;
            }
            while(c<res.back() && cnt[res.back()]){
                visited[res.back()]=false;
                res.pop_back();
                
            }
            res += c;
            visited[c]=true;
        }
        
        return res.substr(1);
    }
