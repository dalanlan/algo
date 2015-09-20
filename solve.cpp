// Surrounded Regions
// Check from outside

// This is an incorrect solution, which does not propogate every 'Y' to its neighbor.
void solve(vector<vector<char>>& board){
	int row = board.size();
	if(row == 0)
		return;
	int col = board[0].size();

	int i,j;
	int left,right,up,bottom;

	left = 0;
	right = col - 1 ;
	up = 0;
	bottom = row - 1 ;
	if(left == right || up == bottom)
		return;
	
	// start from outside
	i=up;j=left;
	while(j<=right)
	{
		if(board[i][j] == 'O')
			board[i][j] = 'Y';
		j++;
	}
	j=right;
	while(i<=bottom)
	{
		if(board[i][j] == 'O')
			board[i][j] = 'Y';
		i++;
	}
	i=bottom;
	while(j>=left)
	{
		if(board[i][j] == 'O')
			board[i][j] = 'Y';
		j--;
	}
	j=left;
	while(i>=up)
	{
		if(board[i][j] == 'O')
			board[i][j] = 'Y';
		i--;
	}
	//done outside
	
	left += 1;
	right -= 1;
	up += 1;
	bottom -= 1;

	while(left <= right || up <= bottom)
	{
		i=up; j=left;
		while(j<=right)
		{
			if(board[i][j]== 'O')
			{
				if(board[i-1][j] == 'Y' || board[i+1][j] == 'Y' || board[i][j-1] == 'Y' || board[i][j+1] == 'Y')
					board[i][j] = 'Y';
			}
			j++;
		}
		j=right;
		while(i<=bottom)
		{
			if(board[i][j] == 'O')
			{
				if(board[i-1][j] == 'Y' || board[i+1][j] == 'Y' || board[i][j-1] == 'Y' || board[i][j+1] == 'Y')
					board[i][j] = 'Y';
			}
			i++;
		}
		i=bottom;
		while(j>=left)
		{
			if(board[i][j] == 'O')
			{
				if(board[i-1][j] == 'Y' || board[i+1][j] == 'Y' || board[i][j-1] == 'Y' || board[i][j+1] == 'Y')
					board[i][j] = 'Y';
			}
			j--;
		}
		j=left;
		while(i>=up)
		{
			if(board[i][j] == 'O')
			{
				if(board[i-1][j] == 'Y' || board[i+1][j] == 'Y' || board[i][j-1] == 'Y' || board[i][j+1] == 'Y')
					board[i][j] = 'Y';
			}
			i--;
		}
		left += 1;
		right -= 1;
		up += 1;
		bottom -= 1;

	}

	for(int i=0;i<row;i++)
		for(int j=0;j<col;j++)
		{
			if(board[i][j] == 'O')
				board[i][j] = 'X';
			if(board[i][j] == 'Y')
				board[i][j] = 'O';
		}	

}


// Solution: bfs
void solve(vector<vector<char>>& board){
	
	int row = board.size();
	if(row == 0)
		return;
	int col = board[0].size();

	
	for(int j=0;j<col;j++){
		bfs(board,0,j);
		bfs(board,row-1,j);
	}
	for(int i=0;i<row;i++){
		bfs(board,i,0);
		bfs(board,i,col-1);
	}

	// 'O' -> 'X'
	// 'Y' -> 'O'
	for(int i=0;i<row;i++)
		for(int j=0;j<col;j++)
		{
			if(board[i][j] == 'O')
				board[i][j] = 'X';
			if(board[i][j] == 'Y')
				board[i][j] = 'O';
		}

}

void bfs(vector<vector<char>>& board, int i, int j){
	if(board[i][j] == 'X')
		return;

	if(board[i][j]=='O')
	{
	board[i][j] = 'Y';
	queue<pair<int,int>> que;
	que.push(make_pair(i,j));

	int row = board.size();
	int col = board[0].size();
	
	int left,right;
	while(!que.empty())
	{
	left = que.front().first;
	right = que.front().second;
	que.pop();

	if(left-1>=0 && board[left-1][right] == 'O')
	{
		board[left-1][right] = 'Y';
		que.push(make_pair(left-1,right));
	}
	if(left+1<=row-1 && board[left+1][right] == 'O')
	{
		board[left+1][right] = 'Y';
		que.push(make_pair(left+1,right));
	}
	if(right-1>=0 && board[left][right-1] == 'O')
	{
		board[left][right-1] = 'Y';
		que.push(make_pair(left,right-1));
	}
	if(right+1<=col-1 && board[left][right+1] == 'O')
	{
		board[left][right+1] = 'Y';
		que.push(make_pair(left,right+1));
	}
	}
	}
	return;

	
}