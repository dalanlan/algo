
/*
LeetCode: text justification
https://leetcode.com/problems/text-justification/


Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly L characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left justified and no extra space is inserted between words.

For example,
words: ["This", "is", "an", "example", "of", "text", "justification."]
L: 16.

*/

class Solution {
public:

    vector<int> makeItFair(int space, int hole) {
        int even = space/hole;
        int odd = space%hole;
        vector<int> v(hole, even);
        int i=0;
        while(odd > 0) {
            v[i++]++;
            odd--;
        }
        return v;
    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
       
        string s("");
        int i=0; 
        
        while(i < words.size()) {
            if(s.empty()) {
                s += words[i++];
            }
            else {
                // space 
                if(s.length() + 1 + words[i].size() <= maxWidth) {
                    s += " "+ words[i++];
                }
                else {
                    int len = s.length();
                    // count remaining characters
                    int remain = maxWidth - len;
                    if(remain == 0) {
                        res.push_back(s);
                    }
                    else {
                        // count space
                        int space = 0;
                        for(int j=0; j<len; j++) {
                            if(s[j] == ' ') {
                                space++;
                            }
                        }
                        if(space == 0) {
                            s += string(remain, ' ');
                            res.push_back(s);
                        }
                        else {
                            // fair.size() == space
                            vector<int> fair = makeItFair(remain, space);
                            
                            string ss("");
                            int j=0;
                            int hole = 0;
                            while(j<len) {
                                ss += s[j];
                                if(s[j] == ' ') {
                                    ss += string(fair[hole++], ' ');
                                }
                                j++;
                            }
                            res.push_back(ss);
                        }
                    }
                    s.clear();
                }
            }
        }
        
        if(!s.empty()) {
            s += string(maxWidth-s.length(), ' ');
            res.push_back(s);
        }
        if(res.size() == 0) {
            res.push_back(string(maxWidth, ' '));
        }
        return res;
    }
};

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        for(int i=0, k, l; i < words.size(); i += k) {
            for(k=l=0; i+k < words.size() && l + words[i+k].size() <= maxWidth - k; k++) {
                l += words[i+k].size();
            }
           
            string tmp = words[i];
            for(int j=0; j < k-1; j++) {
                
                if(i+k >= words.size()) {
                    tmp += " ";
                }
                else {
                    tmp += string((maxWidth-l)/(k-1) +(j < (maxWidth-l)%(k-1)), ' ');
                }
                tmp += words[i+j+1];
               
            }
            tmp += string(maxWidth-tmp.size(), ' ');
            
            res.push_back(tmp);
        }
        return res;
    }
};