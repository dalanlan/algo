/*
https://leetcode.com/problems/decode-string/
394. Decode String
Given an encoded string, return it's decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].
*/


class Solution {
public:

    // traverse from back to front
    // a naive solution
    string decodeString(string s) {
        // from back to the front 
        int pos = s.size()-1;
        while(pos >= 0 && !isdigit(s[pos])) {
            pos--;
        }
        
        
        
        if(pos >=0) {
            
            int posStart = pos;
            while(posStart >= 0 && isdigit(s[posStart])) {
                posStart--;
            }
            // number starts in posStart+1
            int num = 0;
            for(int k=posStart+1; k <= pos; k++) {
                num = num*10+s[k]-'0';
            }
            
            
            int left=pos+1;
            // string starts in left+1 
            int right=left+1;
            while(s[right+1]!= ']') {
                right++;
            }
            // ends in right
            string mid = s.substr(left+1, right-left);
            
            string _mid("");
            for(int i=0; i < num; i++) {
                _mid += mid;
            }
            
            string prefix = s.substr(0, posStart+1);
            string suffix = right+2 < s.size()?s.substr(right+2):"";

            return decodeString(prefix+_mid+suffix);
        }
        
        return s;
        
    }
};





// solution 2:
string decode(string s, int &i) {
    string res;
    while(i < s.size() && s[i] != ']') {
        if(!isdigit(s[i])) {
            res += s[i++];
        }
        else {
            int n=0;
            while(i<s.size() && isdigit(s[i])) {
                n = n * 10 + s[i++] - '0';
            }
            i++;
            string t = decode(s, i);
            i++;
            while(n-- > 0) {
                res += t;
            }
        }
    }
    return res;
}
string decodeString(string s) {
    int i=0;
    return decode(s, i);
}