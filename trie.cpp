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
    vector<TrieNode*> childNodes; // 26-children
	char nodeChar;
	bool isLeaf;
	TrieNode() {
		//childNodes = new TrieNode[26];
		childNodes = vector<TrieNode*>(26,NULL);
		isLeaf = false;
	}
	
	
};

class Trie {
public:
	Trie() {
		root = new TrieNode();
	}

	void insert(string word) {
	    int len = word.length();
		if(len == 0) {
			return;
		}
		insertUtil(root, word);
	}
	void insertUtil(TrieNode* root, string word) {
		int curIndex = word[0] - 'a';
		if(root->childNodes[curIndex] == NULL) {
			root->childNodes[curIndex] = new TrieNode();
			root->childNodes[curIndex]->nodeChar = word[0];
		}
		string nextWord = word.substr(1);
		if(nextWord.size() == 0) {
			root->childNodes[curIndex]->isLeaf = true;
		}
		else {
			insertUtil(root->childNodes[curIndex], nextWord);
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
		if(root->childNodes[curIndex] == NULL) {
			return false;
		}
		string nextWord = word.substr(1);
		if(nextWord.size() == 0) {
			if(root->childNodes[curIndex]->isLeaf == true) {
				return true;
			}
			else {
				return false;
			}
		}
		else {
			return searchUtil(root->childNodes[curIndex], nextWord);
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
		if(root->childNodes[curIndex] == NULL) {
			return false;
		}
		string nextPrefix = prefix.substr(1);
		if(nextPrefix.size() == 0) {
			return true;
		}
		else {
			return startsWithUtil(root->childNodes[curIndex], nextPrefix);
		}
	}

private:
	TrieNode* root;

};



// Solution 2: Use a Hash Map

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

class Trie {
public:
	Trie() {
		root = new TrieNode();
	}

	void insert(string word) {
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
		TrieNode* curRoot = root;
		for(int i=0; i < word.length(); i++) {
			if(curRoot->childNodes.find(word[i]) == curRoot->childNodes.end()) {
				return false;
			}
			curRoot = curRoot->childNodes[word[i]];
		}
		if(curRoot->isLeaf == true) {
			return true;
		}
		else {
			return false;
		}
	}

	bool startsWith(string prefix) {
		TrieNode* curRoot = root;
		for(int i=0; i < prefix.length(); i++) {
			if(curRoot->childNodes.find(prefix[i]) == curRoot->childNodes.end()) {
				return false;
			}
			curRoot = curRoot->childNodes[prefix[i]];
		}
		return true;
	} 
private:
    TrieNode* root;

};