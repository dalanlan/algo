
/*
LintCode: N queens
http://www.lintcode.com/en/problem/n-queens/
*/


// solution 1: back-tracing
// place queen one-by-one
// use column number to recursive

class Solution {
public:
    /**
     * Get all distinct N-Queen solutions
     * @param n: The number of queens
     * @return: All distinct solutions
     * For example, A string '...Q' shows a queen on forth position
     */
    
    // to check whether it's safe to put Queen on board[row][col]
    bool isClear(vector<string> &board, int row, int col, int n) {
        if(row < 0 || row >=n || col < 0 || col >= n) {
            return false;
        }
        
        // check the same row on the left side 
        for(int i=0; i<col; i++) {
            if(board[row][i] == 'Q') {
                return false;
            }
        }
        
        // check upper diagonal on the left side
        for(int i=row, j=col; i>=0 && j>=0; i--, j--) {
            if(board[i][j] == 'Q') {
                return false;
            }
        }
        
        // check lower diagonal on the left side
        for(int i=row, j=col; i<n && j >= 0; i++, j--) {
            if(board[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }
    void solveNQueens(vector<vector<string> > &res, vector<string> &board, int index, int n) {
        if(index == n) {
            res.push_back(board);
            return;
        }
        
        for(int i=0; i<n; i++) {
            if(isClear(board, i, index, n)) {
                board[i][index] = 'Q';
                solveNQueens(res, board, index+1, n);
                board[i][index] = '.';
            }
            
        }
    }
    vector<vector<string> > solveNQueens(int n) {
        // write your code here
        
        vector<vector<string> > res;
        if(n==2 || n == 3 || n <= 0) {
            return res;
        }
        string s(n, '.'); // construction
        vector<string> board(n, s);
        solveNQueens(res, board, 0, n);
        
        return res;
    }
};
