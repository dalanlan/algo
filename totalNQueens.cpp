
/*
LintCode: N queens ii
http://www.lintcode.com/zh-cn/problem/n-queens-ii/
*/


// solution 1: use the same solution of N-queens
class Solution {
public:
    /**
     * Calculate the total number of distinct N-Queen solutions.
     * @param n: The number of queens.
     * @return: The total number of distinct solutions.
     */
    int count = 0;
    bool isClear(vector<string> &board, int row, int col, int n) {
        if(row >= n || col >= n || row < 0 || col < 0) {
            return false;
        }
        
        // check the same row on the left side 
        for(int i=0; i<col; i++) {
            if(board[row][i] == 'Q') {
                return false;
            }
        }
        
        // check the upper diagonal on the left side
        for(int i=row, j=col; i>=0 && j>=0; i--, j--) {
            if(board[i][j] == 'Q') {
                return false;
            }
        }
        
        // check the lower diagonal on the left side
        for(int i=row, j=col; i<n && j>=0; i++, j--) {
            if(board[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }
    void solveNQueens(vector<string> &board, int &count, int index, int n) {
        if(index == n) {
            count++;
            return;
        }
        else {
            for(int i=0; i<n; i++) {
                if(isClear(board, i, index, n)) {
                    board[i][index] = 'Q';
                    solveNQueens(board, count, index+1, n);
                    board[i][index] = '.';
                }
            }
        }
    }
    int totalNQueenstotalNQueens(int n) {
        // write your code here
        if(n < 0 || n == 2 || n == 3) {
            return 0;
        }
        
        string s(n, '.');
        vector<string> board(n, s);
        
        solveNQueens(board, count, 0, n);
        return count;
        
    }
};
