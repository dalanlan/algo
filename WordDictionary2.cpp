/*
LeetCode: add and search word data structure design
https://leetcode.com/problems/add-and-search-word-data-structure-design/

Design a data structure that supports the following two operations:

void addWord(word)
bool search(word)
search(word) can search a literal word or a regular expression string 
containing only letters a-z or .. A . means it can represent any one letter.
*/

class WordDictionary {
	public:
		class TrieNode {
			public:
			unordered_map<char, TrieNode*> map;
			char ch;
			bool isLeaf;
			TrieNode() {
				isLeaf = false;
			}
			TrieNode(char c) {
				ch = c;
				isLeaf = false;
			}
		};

		TrieNode *root;
		
		WordDictionary() {
			root = new TrieNode();
		}
		
		void addWord(string word) {
			TrieNode* cur = root;
			for(int i=0; i<word.size(); i++) {
				if(cur->map.count(word[i]) == 0) {
					cur->map[word[i]] = new TrieNode(word[i]);
				}
				cur = cur->map[word[i]];
			}
			cur->isLeaf = true;
		}

		bool search(TrieNode* node, string word, int index) {
			if(index == word.size()) {
				return node->isLeaf;
			}

			if(word[index] != '.') {
				if(node->map.count(word[index]) == 0) {
					return false;
				}
				else {
					return search(node->map[word[index]], word, index+1);
				}
			}
			else {
				for(auto m:node->map) {
					if(search(m.second, word, index+1)) {
						return true;
					}

				}
				return false;
			}
		}
		bool search(string word) {
			return search(root, word, 0);
		}
};