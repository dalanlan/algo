
/*
LintCode: word ladder
http://www.lintcode.com/zh-cn/problem/word-ladder/
*/

// tip 1: bfs
// tip 2: how to generate neighboring words

class Solution {
public:
    /**
      * @param start, a string
      * @param end, a string
      * @param dict, a set of string
      * @return an integer
      */

    vector<string> neighbors(string s, unordered_set<string> &dict) {
        int len = s.length();
        vector<string> res;
        int pos = 0;
        while(pos < len) {
            char tmp = s[pos];
            for(char c = 'a'; c <= 'z'; c++) {
                if(c == tmp) {
                    continue;
                }
                s[pos] = c;
                if(dict.count(s) == 1) {
                    res.push_back(s);
                    
                }
                s[pos] = tmp;
                
            }
            pos++;
        }
        return res;
    }
    bool isNeighbors(string a, string b) {
        int distance = 0;
        for(int i=0; i<a.length(); i++) {
            if(a[i] != b[i]) {
                distance++;
            }
        }
        return distance == 1;
    }
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // write your code here
        if(start.length() == 0 || end.length() == 0 || dict.size() == 0) {
            return INT_MAX;
        }
        
        queue<pair<string, int>> q;
        q.push(make_pair(start, 1));
        
        while(!q.empty()) {
            pair<string, int> head = q.front();
            q.pop();

            string cur = head.first;
            int lev = head.second;
            
            if(isNeighbors(cur, end)) {
                return lev+1;
            }
            for(auto &x: neighbors(cur, dict)) {
                q.push(make_pair(x, lev+1));
                dict.erase(x);
                
            }       
            
        }
        
        return 0;
        
        
        
    }
};