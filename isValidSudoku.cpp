
/*
LintCode: valid sudoku
http://www.lintcode.com/zh-cn/problem/valid-sudoku/
LeetCode: valid sudoku
https://leetcode.com/problems/valid-sudoku/
*/

// AC on leetcode 
// 'cause lintcode does not support bitset
// which can be replaced by vector<bool>

class Solution {
public:
   bool isValidSudoku(const vector<vector<char>>& board) {
        if(board.size() != 9 || board[0].size() != 9) {
            return false;
        }
        // check different cols in the same row
        for(int i=0; i<9; i++) {
            bitset<9> used;
            for(int j=0; j<9; j++) {
                if(board[i][j] == '.') {
                    continue;
                }
                else {
                    // board[i][j], i is set
                    int num = board[i][j] - '1';
                    
                    if(num < 0 || used[num]) {
                        
                        return false;
                    }
                    used.set(num);
                }
            }
        }
        
        // check differen rows in the same col
        for(int i=0; i<9; i++) {
            bitset<9> used;
            for(int j=0; j<9; j++) {
                if(board[j][i] == '.') {
                    continue;
                }
                else {
                    int num = board[j][i] - '1';
                    if(num < 0 || used[num]) {
                       
                        return false;
                    }
                    used.set(num);
                }
            }
            
        }
        
        // check different blocks
        
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                int row = i*3;
                int col = j*3;
                bitset<9> used;
                for(int m=row; m<row+3; m++) {
                    for(int n=col; n<col+3; n++) {
                        if(board[m][n] == '.') {
                            continue;
                        }
                        else {
                            int num = board[m][n] - '1';
                            if(num < 0 || used[num]) {
                                
                                return false;
                            }
                            used.set(num);
                        }
                    }
                }
            }
            
        }
        return true;
        
    }
};