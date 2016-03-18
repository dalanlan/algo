
/*
LeetCode: maximum product of word lengths
https://leetcode.com/problems/maximum-product-of-word-lengths/
*/

// note that the priority of `&` is so very low
class Solution {
public:
    int maxProduct(vector<string>& words) {
        //sort(words.begin(), words.end());
        
        vector<int> mask;
        for(int i=0; i<words.size(); i++) {
            int tmp=0;
            for(char c:words[i]) {
                tmp |= 1 << (c-'a');
            }
            mask.push_back(tmp);
        }
        
        int res = 0;        
        for(int i=0; i<words.size(); i++) {
            int len = words[i].length();
            
            for(int j=i+1; j<words.size(); j++) {
                int len2 = words[j].length();
                if((mask[i] & mask[j]) == 0) {
                    
                    res = max(res, len*len2);
                }
            }
        }
        return res; 
    }
};