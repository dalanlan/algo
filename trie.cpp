// Implement Trie (Prefix Tree)

/*
Implement a trie with `insert`, `search`, and 
`startsWith` methods.

Called as such:

Trie trie;
trie.insert("something");
trie.search("kev");
*/


class TrieNode {
public:

	TrieNode[] childNodes; // 26-children
	char nodeChar;
	bool isLeaf;
	
	TrieNode() {
		childNodes = new TrieNode[26];
		ifLeaf = false;
	}
};

class Trie {
public:
	Trie() {
		root = new TrieNode();
	}

	void insert(string word) {
		insertUtil(root, word);
	}
	void insertUtil(TrieNode* root, string word) {
		int len = word.length();
		if(len == 0) {
			return;
		}

		int curIndex = word[0] - 'a';
		if(root.childNodes[curIndex] == NULL) {
			root.childNodes[curIndex] = new TrieNode();
			root.childNodes[curIndex].nodeChar = word[0];
		}
		string nextWord = word.subString(1);
		if(nextWord.size() == 0) {
			root.childNodes[curIndex].isLeaf = true;
		}
		else {
			insertUtil(root.childNodes[curIndex], nextWord;
		}
	}

	bool search(string word) {
		if(word.length() == 0) {
			return false;
		}
		return searchUtil(root, word);
	}

	bool searchUtil(TrieNode* root, string word) {
		int curIndex = word[0]-'a';
		if(root.childNodes[curIndex] == NULL) {
			return false;
		}
		string nextWord = word.subString(1);
		if(nextWord.size() == 0) {
			if(root.isLeaf) {
				return true;
			}
			else {
				return false;
			}
		}
		else {
			return searchUtil(root.childNodes[curIndex], nextWord);
		}	
	}

	bool startsWith(string prefix) {
		if(prefix.length() == 0) {
			return false;
		}
		return startsWithUtil(root, prefix);
	}

	bool startsWithUtil(TrieNode* root, string prefix) {
		int curIndex = prefix[0] - 'a';
		if(root.childNodes[curIndex] == NULL) {
			return false;
		}
		string nextPrefix = prefix.subString(1);
		if(nextPrefix.size() == 0) {
			return true;
		}
		else {
			return startsWithUtil(root.childNodes[curIndex], nextPrefix);
		}
	}

private:
	TrieNode* root;

}