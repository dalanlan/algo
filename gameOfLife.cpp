
/*
Leetcode: game of life
https://leetcode.com/problems/game-of-life/
*/

class Solution {
public:
    // not in-place
    // extra space
    
    int countLiveNeigh(vector<vector<int>>& board, int row, int col, int i, int j) {
        int count = 0;
        
        // up
        if(i > 0 && board[i-1][j] == 1) {
            count++;
        }
        // down
        if(i < row-1 && board[i+1][j] == 1) {
            count++;
        }
        //left
        if(j > 0 && board[i][j-1] == 1) {
            count++;
        }
        
        //right
        if(j < col-1 && board[i][j+1] == 1) {
            count++;
        }
        // left-upper
        if(i > 0 && j > 0 && board[i-1][j-1] == 1) {
            count++;
        }
        // right-upper
        if(i > 0 && j<col-1 && board[i-1][j+1] == 1) {
            count++;
        }
        // left-down
        if(j>0 && i<row-1 && board[i+1][j-1] == 1) {
            count++;
        }
        
        //right-down
        if(j<col-1 && i<row-1 && board[i+1][j+1] == 1) {
            count++;
        }
        return count;
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        if(board.size() == 0 || board[0].size() == 0) {
            return;
        }
        int row = board.size();
        int col = board[0].size();
        
        vector<vector<int>> next=vector<vector<int>>(row, vector<int>(col, 0));
        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                int live = countLiveNeigh(board, row, col, i, j);
                cout<<live<<endl;
                if(live < 2 && board[i][j] == 1) {
                    next[i][j] = 0;
                }
                else if((live == 2 || live == 3) && board[i][j] == 1) {
                    next[i][j] = 1;
                }
                else if(live > 3 && board[i][j] == 1) {
                    next[i][j] = 0;
                }
                else if(live == 3 && board[i][j] == 0) {
                    next[i][j] = 1;
                }
            }
        }
        board = next;

        return;
    }
};




// can you solve it in-place

