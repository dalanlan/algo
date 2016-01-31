/*
LintCode: surrounded regions
http://www.lintcode.com/zh-cn/problem/surrounded-regions/
*/


class Solution {
public:
    /**
     * @param board a 2D board containing 'X' and 'O'
     * @return void
     */
    void surroundedRegions(vector<vector<char>>& board) {
        
        int row = board.size();
        if(row == 0) {
            return;
        }
        int col = board[0].size();
        // initialized
        vector<vector<int>> visited(row, vector<int>(col, 0));
        
        for(int i=0; i<row; i++) {
            if(visited[i][0] == 0 && board[i][0] == 'O') {
                dfs(board, visited, i, 0, row, col);
            }
            if(visited[i][col-1] == 0 && board[i][col-1] == 'O') {
                dfs(board, visited, i, col-1, row, col);
            }
        }
        for(int j=0; j<col; j++) {
            if(visited[0][j] == 0 && board[0][j] == 'O') {
                dfs(board, visited, 0, j, row, col);
            }
            if(visited[row-1][j] == 0 && board[row-1][j] == 'O') {
                dfs(board, visited, row-1, j, row, col);
            }
        }
        // color back
        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                if(board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                else if(board[i][j] == 'Y') {
                    board[i][j] = 'O';
                }
            }
        }
    }
    
    void dfs(vector<vector<char>>& board, vector<vector<int>>& visited, int i, int j, int row, int col) {
        //set flag
        visited[i][j] = 1;
        board[i][j] = 'Y';
        // left [i][j-1]
        if(j>0 && board[i][j-1]== 'O' && visited[i][j-1] == 0) {
            dfs(board, visited, i, j-1, row, col);
        }
        // right [i][j+1]
        if(j+1<col && board[i][j+1] == 'O' && visited[i][j+1] == 0) {
            dfs(board, visited, i, j+1, row, col);
        }
        // up [i-1][j]
        if(i>0 && board[i-1][j] == 'O' && visited[i-1][j] == 0) {
            dfs(board, visited, i-1, j, row, col);
        }
        // down[i+1][j] 
        if(i+1<row && board[i+1][j] == 'O' && visited[i+1][j] == 0) {
            dfs(board, visited, i+1, j, row, col);
        }
    }
};