
/*
LeetCode: word search II
https://leetcode.com/problems/word-search-ii/

Given a 2D board and a list of words from the dictionary, find all words in the board.

Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.



*/

class Solution {
public:
    /**
     * @param board: A list of lists of character
     * @param words: A list of string
     * @return: A list of string
     */
     
    // trie tree
    class TrieNode {
    public:
        string word;
        vector<TrieNode*> child;
        
        // contruction function
        TrieNode() {
            child = vector<TrieNode*>(26, NULL);
        }
    };
    
    
    void wordSearch(vector<vector<char>> &board, int row, int col, int i, int j, TrieNode* root, vector<string> &res) {
        
        if(i < 0 || i>= row || j < 0 || j >= col) {
            return ;
        }
        
        char c=board[i][j];
        
        if(c == '#' || root->child[c-'a'] == NULL) {
            return;
        }
        root = root->child[c-'a'];
        
        if(!root->word.empty()) {
            res.push_back(root->word);
            root->word = "";
        } 
        
        board[i][j] = '#';
        
        wordSearch(board, row, col, i+1, j, root, res);
        wordSearch(board, row, col, i-1, j, root, res);
        wordSearch(board, row, col, i, j+1, root, res);
        wordSearch(board, row, col, i, j-1, root, res);
        board[i][j] = c;
        
        

    }
    
    TrieNode* constructTree(vector<string> &words) {
        TrieNode* root = new TrieNode();
        
        for(string s: words) {
            TrieNode *cur = root;
            for(char c:s) {
                if(cur->child[c-'a'] == NULL) {
                    cur->child[c-'a'] = new TrieNode();    
                }
                cur = cur->child[c-'a'];
            }
            cur->word = s;
        }
        return root;
        
    } 
    vector<string> findWords(vector<vector<char> > &board, vector<string> &words) {
        // write your code here
        vector<string> res; 
        if(board.size() == 0 || board[0].size() == 0 || words.size() == 0) {
            return res;
        }
        
        TrieNode* root = constructTree(words);
        
        int row = board.size();
        int col = board[0].size(); 
        
        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                wordSearch(board, row, col, i, j, root, res);
            }
        }

        return res;
        
    }
};