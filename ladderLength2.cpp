
/*
LeetCode: 127 Word Ladder
https://leetcode.com/problems/word-ladder/

Given two words (beginWord and endWord), and a dictionary's word list, 
find the length of shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the word list
For example,

Given:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.
*/


class Solution {
public:
    unordered_set<string> neighbor(string word, unordered_set<string>& wordList) {
        unordered_set<string> res;
        
        for(int i=0; i<word.size(); i++) {
            char c = word[i];
            for(char ch='a'; ch <= 'z'; ch++) {
                if(ch == c) {
                    continue;
                }
                word[i] = ch;
                if(wordList.count(word)) {
                    res.insert(word);
                    wordList.erase(word);
                }
            }
            word[i] = c;
        }
        return res;
    }
    
    bool isNeighbor(string word1, string word2) {
        int dist = 0; 
        int len = word1.size();
        for(int i=0; i<len; i++) {
            if(word1[i] != word2[i]) {
                dist++;
            }
        }
        return dist == 1;
    } 
    
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
    
        int cnt = 0;
        
        queue<string> q;
        q.push(beginWord);
        
        while(!q.empty()) {
            int sz = q.size();
            cnt++;
            
            for(int i=0; i<sz; i++) {
                string tmp = q.front();
                q.pop();
                if(isNeighbor(tmp, endWord)) {
                    return ++cnt;
                }
                unordered_set<string> neigh = neighbor(tmp, wordList);
                for(auto s:neigh) {
                    q.push(s);
                }
            }
        }
        return 0;
            
    }
};