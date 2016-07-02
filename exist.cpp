    bool dfs(vector<vector<char>>& board, vector<vector<int>>& visit, int row, int col, string word, int index) {
	int rowMax = board.size();
	int colMax = board[0].size();

	if(row >= rowMax || row < 0 || col >= colMax || col < 0) return false;
	
	if(board[row][col] == word[index] && visit[row][col] == 0){ 
		visit[row][col] = 1;
		if (index == word.length()-1) {
			return true;
		}
		else {
			if(dfs(board, visit, row+1, col, word, index+1) || dfs(board, visit, row, col+1 , word, index+1) ||
			dfs(board, visit, row-1, col, word, index+1)||dfs(board, visit, row, col-1, word, index+1)) {
				return true;
			}

		}	
		visit[row][col] = 0;

	}
	return false;
	

	
}
bool exist(vector<vector<char>>& board, string word) {
	if (board.size() == 0)
		return false;
	int row = board.size();
	int col = board[0].size();
	vector<vector<int>> visit(row, vector<int>(col, 0));
	

	for(int i=0; i< row;i++) {
		for(int j=0;j < col;j++) {
			if(dfs(board, visit, i, j, word, 0)){
				return true;
			}

		}

	}
	

	return false;

}

// use TrieNode

class TrieNode {
    public:
    string word;
    vector<TrieNode*> child;
    
    TrieNode() {
        child = vector<TrieNode*>(256, NULL);
        
    }
};

TrieNode* construct(string word) {
    TrieNode *root = new TrieNode();
    TrieNode *cur = root;
    for(char c:word) {
        if(cur->child[c-'A'] == NULL) {
            cur->child[c-'A'] = new TrieNode();
        }
        cur = cur->child[c-'A'];
        
    }
    cur->word = word;
    return root;
}


bool exist(vector<vector<char>>& board, int i, int j, int row, int col, string word, TrieNode* root) {
    if(i < 0 || i >= row || j < 0 || j >= col) {
        return false;
    }
    char c = board[i][j];
    if(c == '#' || root->child[c-'A'] == NULL) {
        return false;
    }
    
    root = root->child[c-'A'];
    
    if(!root->word.empty()) {
        return true;
    }
    board[i][j] = '#';
   
    if(exist(board, i+1, j, row, col, word, root) ||
       exist(board, i-1, j, row, col, word, root) ||
       exist(board, i, j+1, row, col, word, root) ||
       exist(board, i, j-1, row, col, word, root)) {
           return true;
       }
    board[i][j] = c;
    return false;
    
    
} 
bool exist(vector<vector<char>>& board, string word) {
    
    TrieNode* root = construct(word);

    int row = board.size();
    int col = row==0?0:board[0].size();
    
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            if(exist(board, i, j, row, col, word, root)) {
                return true;
            }
        }
    }
    return false;
}