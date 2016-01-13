/*

LintCode 433: the number of islands

Given a matrix with 0 and 1 inside. 0 stands for
sea while 1 the island. If two 1s adjacent, we say 
they belong to the same island.
Please find out the number of islands.

In the following cases, we have 3 islands.
[
  [1, 1, 0, 0, 0],
  [0, 1, 0, 0, 1],
  [0, 0, 0, 1, 1],
  [0, 0, 0, 0, 0],
  [0, 0, 0, 0, 1]
]


*/

/**
 * @param grid a boolean 2D matrix
 * @return an integer
 */
int numIslands(vector<vector<bool>>& grid) {
    // Write your code here
    int row = grid.size();
    if(row == 0) {
    	return 0;
    }
    int col = grid[0].size();
    if(col == 0) {
    	return 0;
    }

    // whether grid[i][j] is visited
    vector<vector<bool>> isVisited(row, vector<bool>(col, 0));

    int count = 0;
    for(int i = 0; i < row; i++) {
    	for(int j = 0; j < col; j++) {
    		if(grid[i][j] == 1 && isVisited[i][j] == 0) {
    			count++;
    			dfs(grid,isVisited,i,j,row,col);
    		}
    	}
    }
    return count;
}

void dfs(vector<vector<bool>>& grid, vector<vector<bool>>& isVisited, int i, int j, int row, int col) {
	isVisited[i][j] = 1;
	//left
	if(i > 0 && isVisited[i-1][j] == 0 && grid[i-1][j] == 1) {
		dfs(grid, isVisited, i-1, j, row, col);
	}
	//right
	if(i < row-1 && isVisited[i+1][j] == 0 && grid[i+1][j] == 1) {
		dfs(grid, isVisited, i+1, j, row, col);
	}
	//up
	if(j > 0 && isVisited[i][j-1] == 0 && grid[i][j-1] == 1) {
		dfs(grid, isVisited, i, j-1, row, col);
	}
	//down
	if(j < col -1 && isVisited[i][j+1] == 0 && grid[i][j+1] == 1) {
		dfs(grid, isVisited, i, j+1, row, col);
	}

}

