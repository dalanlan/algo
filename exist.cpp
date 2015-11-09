void bfs(vector<vector<char>>& board, vector<vector<int>>& visit, int row, int col, string word, int& index) {
	cout<<row<<" "<<col<<" ,index: "<<index<<endl;
	index++;
	visit[row][col] = 1;
	if(index == word.length())
		return;
	
	if(row > 0 && visit[row-1][col] == 0 && board[row-1][col] == word[index]) { // left
		cout<<"up"<<endl;
		bfs(board, visit, row-1, col, word, index);
		
	}
	if(col > 0 && visit[row][col-1] == 0 && board[row][col-1] == word[index]) { 
		cout<<"left"<<endl;
		bfs(board, visit, row, col-1, word, index);
		
	}
	if(row < board.size() - 1 && visit[row+1][col] == 0 && board[row+1][col] == word[index]) {
		cout<<"down"<<endl;
		bfs(board, visit, row+1, col, word, index);
		
	}
	if(col < board[0].size() - 1 && visit[row][col+1] == 0 && board[row][col+1] == word[index]) {
		cout<<"right"<<endl;
		bfs(board, visit, row, col+1, word, index);
		
	}

	
}
bool exist(vector<vector<char>>& board, string word) {
	if (board.size() == 0)
		return false;
	int row = board.size();
	int col = board[0].size();
	int index = 0;
	vector<vector<int>> visit(row, vector<int>(col, 0));
	

	for(int i = 0; i < row; i++) {
		for(int j = 0; j < col; j++) {
			if(visit[i][j] == 0 && board[i][j] == word[index]) {
				bfs(board, visit, i, j, word, index);
				
	            if(index == word.length())
		            return true;
		        else {
		            index = 0;
		            vector<vector<int>> visit(row, vector<int>(col, 0));
		        }
			}
		}
	}

	return false;

}