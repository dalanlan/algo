
/*
Lintcode: reverse words in a string 
http://www.lintcode.com/zh-cn/problem/reverse-words-in-a-string/
*/

class Solution {
public:
    // solve it with extra space
    
    vector<string> split(string s, char del) {
        vector<string> res;
        stringstream ss(s);
        string token;
        while(getline(ss, token, del)) {
            res.push_back(token);
        }
        return res;
    }
    void reverseWords(string &s) {
        vector<string> res = split(s, ' ');
        string ans;
        for(int i=res.size()-1; i>=0; i--) {
            if(res[i] == "") {
                continue;
            }
            else {
                if(ans.empty()) {
                    ans += res[i];
                }
                else {
                    ans += " "+ res[i];
                }
            }
        }
        s = ans;
    }
};

// solution 2: in-place reverse
  void reverseWords(string &s) {
        reverse(s.begin(), s.end());
        
        int curInd = 0;
        for(int i=0; i<s.size(); i++) {
            
            if(s[i] != ' ') {
                if(curInd != 0) {
                    s[curInd++] = ' ';
                }
                int j=i;
                while(j<s.size() && s[j] != ' ') {
                    s[curInd++] = s[j++];
                }
                reverse(s.begin()+curInd-(j-i), s.begin()+curInd);
                i=j;
            }
        }
        // wipe out extra space
        s.erase(s.begin()+curInd, s.end());
    }