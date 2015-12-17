// Add and Search Word - Data Structure design

/*
Design a data structure that supports the following
two operations:

void addWord(word)
void search(word)

search(word) can search a literal word or a regular
expression string containing only letters "a"-"z" or ".".
A "." means that it can represent any one letter.

addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true

*/


class TrieNode {
public:
	unordered_map<char, TrieNode*> childNodes;
	char nodeChar;
	bool isLeaf;
	TrieNode() {
		isLeaf = false;
	}
	TrieNode(char c) {
		nodeChar = c;
		isLeaf = false;
	}
};


class WordDictionary {
public:
	
	WordDictionary() {
		root = new TrieNode();
	}
	// Adds a word into the data structure.
	void addWord(string word) {
		TrieNode* curRoot = root;
		for(int i=0; i < word.length(); i++) {
			if(curRoot->childNodes.find(word[i]) == curRoot->childNodes.end()) {
				curRoot->childNodes[word[i]] = new TrieNode(word[i]);
			}
			curRoot = curRoot->childNodes[word[i]];
		}
		curRoot->isLeaf = true;
	}
	

	bool search(string word) {
		return searchUtil(root, 0, word); // TrieNode*, index, string word
	}
	bool searchUtil(TrieNode* root, int index, string word) {
		if(index == word.length()) {
			return root->isLeaf;
		}

		if(word[index] == '.') {
			for(auto c : root->childNodes) {
				if(searchUtil(c.second, index+1, word) == true) {
					return true;
				}
			}
			return false;
		}
		// word[index] != '.'
		else {
			if(root->childNodes.find(word[index]) == root->childNodes.end()) {
				return false;
			}
			else {
				return searchUtil(root->childNodes[word[index]], index+1, word);
			}
		}

	}

	private:

	TrieNode* root;

};