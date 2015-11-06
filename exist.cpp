// Word Search


void bfs(vector<vector<char>>& board, vector<vector<int>>& visit, int row, int col, string word, int& index) {
	if(index == word.length())
		return; 
	if(board[row][col] == word[index]) {
		index++;
		bfs(board,)
	}
	
	
	
}
bool exist(vector<vector<char>>& board, string word) {
	if (board.size() == 0)
		return false;
	int row = board.size();
	int col = board[0].size();
	int index = 0;
	vector<vector<int>> visit(row, vector<int>(col)) ;
	if()

}