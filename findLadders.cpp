
/*
Leetcode: Word Ladder II
https://leetcode.com/problems/word-ladder-ii/

Given two words (beginWord and endWord), and a dictionary's word list, find all shortest transformation sequence(s) from beginWord to endWord, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the word list
For example,

Given:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]
Return
  [
    ["hit","hot","dot","dog","cog"],
    ["hit","hot","lot","log","cog"]
  ]

*/

class Solution {
public:
   vector<vector<string>> findLadders(string start, string end, unordered_set<string>& wordList) {
       
       vector<vector<string>> res;
       unordered_map<string, vector<string>> father;
       
       unordered_set<string> current;
       unordered_set<string> next;
       
       unordered_set<string> visited;
       
       current.insert(start);
       bool found = false;
       
       while(!current.empty() && !found) {
           for(auto x: current) {
               visited.insert(x);
           }
           
           for(auto x: current) {
              string orig = x;
               for(int i=0; i<x.size(); i++) {
                   for(char c='a'; c <= 'z'; c++) {
                       if(x[i] == c) {
                           continue;
                       }
                       orig[i] = c;
                       if(orig == end) {
                           found = true;
                       }
                       
                       if(visited.count(orig) == 0 && wordList.count(orig) >0) {
                           next.insert(orig);
                           father[orig].push_back(x);
                           
                       }
                       orig[i] = x[i];
                   } 
               }
           }
           
           current = next;
           next.clear();
       }
    
      
       vector<string> path;
       if(found) {
           backTrace(res, path, father, start, end);
       }
       return res;
   }
   
   void backTrace(vector<vector<string>>& res, vector<string>& path, unordered_map<string, vector<string>> &father, string start, string current) {
       if(start == current) {
           path.insert(path.begin(), start);
           res.push_back(path);
           path.erase(path.begin());
       }
       else {
           path.insert(path.begin(), current);
           for(auto x: father[current]) {
               backTrace(res, path, father, start, x);
           }
           path.erase(path.begin());
       }
   }
   
};


// rewrite, the same as before though
vector<vector<string>> findLadders(string start, string end, unordered_set<string>& wordList) {
        vector<vector<string>> res;
        
        unordered_set<string> cur;
        unordered_set<string> next;
        
        unordered_set<string> visited;
        unordered_map<string, vector<string>> father;
    
        bool found = false;
        
        
        cur.insert(start);
        
        while(!cur.empty() && !found) {
            for(auto x:cur) {
                visited.insert(x);
            }
            
            for(auto x:cur) {
                string tmp = x;
                for(int i=0; i<tmp.size(); i++) {
                    for(char c = 'a'; c <= 'z'; c++) {
                        if(c == tmp[i]) {
                            continue;
                        }
                        if(tmp == end) {
                            found = true;
                        }
                        tmp[i] = c;
                        if(wordList.count(tmp) > 0 && visited.count(tmp) == 0) {
                            next.insert(tmp);
                            father[tmp].push_back(x);
                        }
                        
                    }
                    tmp[i] = x[i];
                }
            }
            cur = next;
            next.clear();
            
        }
        vector<string> path;
        
        if(found) {
            backTrace(res, path, father, start, end);
        }
        return res;
        
        
}
void backTrace(vector<vector<string>> &res, vector<string>& path, unordered_map<string, vector<string>> &father, string start, string current) {
    path.insert(path.begin(), current);
    if(current == start) {
        res.push_back(path);
    }
    else {
        for(auto x:father[current]) {
            backTrace(res, path, father, start, x);
        }
        
    }
    path.erase(path.begin());
}