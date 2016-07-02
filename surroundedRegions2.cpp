
/*
LeetCode: surrounded regions
https://leetcode.com/problems/surrounded-regions/

*/

class Solution {
public:

    // a problem of coloring
    void solve(vector<vector<char>>& board) {
        if(board.size() == 0 || board[0].size() == 0) {
            return;
        }
        
        int row = board.size();
        int col = board[0].size();
        
        for(int i=0; i < row; i++) {
            // board[i][0]
            dfs(board, i, 0, row, col);
            
            if(col > 1) {
                dfs(board, i, col-1, row, col);
            }
        }
        for(int i=0; i < col; i++) {
            dfs(board, 0, i, row, col);
            
            if(row > 1) {
                dfs(board, row-1, i, row, col);
            }
        }
        
        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                if(board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                else if(board[i][j] = 'Y') {
                    board[i][j] = 'O';
                }
            }
        }
    }
    
    void dfs(vector<vector<char>>& board, int i, int j, int row, int col) {
        if(i < 0 || i >= row || j < 0 || j >= col) {
            return;
        }
        if(board[i][j] != 'O'){
            return;
            
        }
        board[i][j] = 'Y';
        dfs(board, i+1, j, row, col);
        dfs(board, i-1, j, row, col);
        dfs(board, i, j+1, row, col);
        dfs(board, i, j-1, row, col);
        
        
    }
};