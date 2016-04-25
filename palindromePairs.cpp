

/*
LeetCode: palindrome pairs
https://leetcode.com/problems/palindrome-pairs/
*/

// solution 1: naive solution
// TLE

// solution 2: 
// https://leetcode.com/discuss/93599/easy-to-understand-ac-c-solution-o-n-k-2-using-map
class Solution {
public:

    bool isPalindrome(string s) {
        int i=0, j=s.length()-1;
        while(i < j) {
            if(s[i++] != s[j--]) {
                return false;
            }
        }
        return true;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> res;
        if(words.size() == 0) {
            return res;
        }
        
        unordered_map<string,int> map;
        for(int i=0; i<words.size(); i++) {
            string tmp = words[i];
            reverse(tmp.begin(), tmp.end());
            map[tmp] = i;
        }
        
        if(map.count("") != 0) {
            int pos = map[""];
            for(int i=0; i<words.size(); i++) {
                if(words[i] != "" && isPalindrome(words[i])) {
                    res.push_back({pos, i});
                }
                    
            }
        }
        
        for(int i=0; i<words.size(); i++) {
            string tmp = words[i];
            for(int j=0; j<tmp.length(); j++) {
                string left = tmp.substr(0, j);
                string right = tmp.substr(j);
                if(map.count(left) != 0 && isPalindrome(right) && map[left] != i) {
                    res.push_back({i, map[left]});
                }
                if(map.count(right) != 0 && isPalindrome(left) && map[right] != i) {
                    res.push_back({map[right], i});
                }
            }
            
        }
        return res;
    }
};