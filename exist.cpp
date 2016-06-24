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