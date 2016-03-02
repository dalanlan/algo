
/*
LeetCode: sudoku solver
https://leetcode.com/problems/sudoku-solver/

*/

// back-tracking
// from left to right
// hash table to indicate whether it's been used?

// https://leetcode.com/discuss/51303/two-very-simple-and-neat-c-dfs-backtracking-solutions
// use 2D vector to store used bit 
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
	
	// row[i][j] == 1 : means j is no more available in the ith row
	vector<vector<bool>> row = vector<vector<bool>>(9, vector<bool>(9, false));
	// col[i][j] == 1: means j is no more available in the ith col
	vector<vector<bool>> col = vector<vector<bool>>(9, vector<bool>(9, false));
	// sub[i][j] == 1: means j is no more available in the jth submatrix
    vector<vector<bool>> sub = vector<vector<bool>>(9, vector<bool>(9, false));
    
	for(int i=0; i<9; i++) {
		for(int j=0; j<9; j++) {
			if(board[i][j] != '.') {
				int num = board[i][j] - '1';
				int k = i/3*3+j/3;
				row[i][num] = col[j][num] = sub[k][num] = true;
			}
		}
	}

	solver(board, row, col, sub, 0);
}

bool solver(vector<vector<char>>& board, vector<vector<bool>>& row, vector<vector<bool>>& col, vector<vector<bool>>& sub, int index) {
	if(index == 81) {
		return true;
	}
	int r = index/9;
	int c = index%9;
	int b = r/3*3 + c/3;

	if(board[r][c] != '.') {
		return solver(board, row, col, sub, index+1);
	}

	for(char x = '1'; x<='9'; x++) {
        //int cur = x-'1';
		if(row[r][x-'1'] || col[c][x-'1'] || sub[b][x-'1']) {
			continue;
		}
		board[r][c] = x;
		row[r][x-'1'] = col[c][x-'1'] = sub[b][x-'1'] = true;
		if(solver(board, row, col, sub, index+1)) {
			return true;
		}
		board[r][c] = '.';
		row[r][x-'1'] = col[c][x-'1'] = sub[b][x-'1'] = false;
	}
	return false;
}
};