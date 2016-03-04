
/*
LintCode: word search ii
http://www.lintcode.com/zh-cn/problem/word-search-ii/
LeetCode: word search ii

*/

// solution 1: considering the length of 
// the code, it's a disaster

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
        char ch;
        bool isLeaf;
        vector<TrieNode*> child;
        // contruction function
        TrieNode() {
            isLeaf = false;
            child = vector<TrieNode*>(26, NULL);
        }
        TrieNode(char c) {
            ch = c;
            isLeaf = false;
            child = vector<TrieNode*>(26, NULL);
        }
    };
    
    class TrieTree {
    public:
        TrieNode* root;
        TrieTree() {
            // empty node
            root = new TrieNode();   
        }
        
        // insert word
        void insertWord(string word) {
            TrieNode* cur = root;
            int ind = 0;
            while(ind < word.length()) {
                int index = word[ind]-'a';
                if(cur->child[index] == NULL) {
                    cur->child[index] = new TrieNode();
                    cur->child[index]->ch = word[ind];
                }
                cur = cur->child[index];
                ind++;
            }
            cur->isLeaf = true;
        }
        bool searchWord(string word) {
            int ind = 0;
            TrieNode* cur = root;
            while(ind < word.length()) {
                int index = word[ind] - 'a';
                if(cur->child[index] == NULL) {
                    return false;
                }
                cur = cur->child[index];
                ind++;
            }
            return cur->isLeaf;
        }
        
        bool startWith(string prefix) {
            int ind = 0;
            TrieNode* cur = root;
            while(ind < prefix.length()) {
                int index = prefix[ind] - 'a';
                if(cur->child[index] == NULL) {
                    return false;
                }
                cur = cur->child[index];
                ind++;
            }
            return true;
        }
    };
    
    void wordSearch(vector<vector<char>> &board, int row, int col, string path, vector<vector<bool>> &used, int i, int j, TrieTree* tree, unordered_set<string> &res) {
        if(i < 0 || i>= row || j < 0 || j >= col) {
            return ;
        }
        if(tree->searchWord(path)) {
            if(res.count(path) == 0) {
                res.insert(path);
            }
            
        }
        
        if(used[i][j]) {
            return ;
        }
        string tmp = path;
        path += board[i][j];
        if(!tree->startWith(path)) {
            path = tmp;
            return ;
        }
        used[i][j] = true;
        wordSearch(board, row, col, path, used, i+1, j, tree, res);
        wordSearch(board, row, col, path, used, i-1, j, tree, res);
        wordSearch(board, row, col, path, used, i, j+1, tree, res);
        wordSearch(board, row, col, path, used, i, j-1, tree, res);

        path = tmp;
        used[i][j] = false;

    }
    vector<string> wordSearchII(vector<vector<char> > &board, vector<string> &words) {
        // write your code here
        vector<string> res; 
        if(board.size() == 0 || board[0].size() == 0 || words.size() == 0) {
            return res;
        }
        
        TrieTree* tree = new TrieTree();
        for(int i=0; i<words.size();i++) {
            tree->insertWord(words[i]);
        }
        
        int row = board.size();
        int col = board[0].size(); 
        vector<vector<bool>> used = vector<vector<bool>> (row, vector<bool>(row, false));
        
        string path;
        unordered_set<string> ans;
        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                
                wordSearch(board, row, col, path, used, i, j, tree, ans);
            }
        }
        for(auto &x:ans) {
            res.push_back(x);
        }
        return res;
        
    }
};

// solution 1 has potential overhead
// should try:
// (1) deprecate 2d vector `used` 
// (2) use hashmap to store the children of each TrieNode
// (3) use a new way to explore children of TrieNode