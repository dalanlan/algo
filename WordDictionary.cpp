/*
LintCode: add and search word 
http://www.lintcode.com/zh-cn/problem/add-and-search-word/

*/



class TrieNode {
public:
    vector<TrieNode*> child;
    bool isLeaf;
    char ch;
    
    TrieNode() {
        child = vector<TrieNode*>(26, NULL);
        isLeaf = false;
    }
    TrieNode(char c) {
        child = vector<TrieNode*>(26, NULL);
        isLeaf = false;
        ch = c;
    }
};

class WordDictionary {
public:
    TrieNode* root;
    // construction function
    WordDictionary() {
        root = new TrieNode();
    }
    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode *curRoot = root;
        int index;
        for(int i=0; i<word.length(); i++) {
            index = word[i]-'a';
            if(curRoot->child[index] == NULL) {
                curRoot->child[index] = new TrieNode(word[i]);
            }
            curRoot = curRoot->child[index];
        }
        curRoot->isLeaf = true;
        
    }

    bool searchUtil(string word, int index, TrieNode* root) {
        if(index == word.length()) {
                return root->isLeaf;
        }
        
        if(word[index] == '.') {
            for(int i=0; i<root->child.size(); i++) {
                if(root->child[i] != NULL && searchUtil(word, index+1, root->child[i])) {
                    return true;
                }
            }
            return false;
        }
        else {
            int ind = word[index] -'a';
            if(root->child[ind] == NULL) {
                return false;
            }
            return searchUtil(word, index+1, root->child[ind]);
        }
        
    }
    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        if(word.length() == 0) {
            return true;
        }
        return searchUtil(word, 0, root);
        
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");