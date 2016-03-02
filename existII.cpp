
/*
LintCode: word search
http://www.lintcode.com/zh-cn/problem/word-search/
*/

class Solution {
public:
    /**
     * @param board: A list of lists of character
     * @param word: A string
     * @return: A boolean
     */
    
    bool exist(int i, int j, vector<vector<char> > &board, string word, vector<vector<bool> > &visited, int row, int col, int index) {
        if(i<0 || j<0 || i >= row || j >= col) {
            return false;
        }
        
        if(index == word.length()-1) {
            return board[i][j] == word[index];
        }
        
        
        if(board[i][j] != word[index]) {
            return false;
        }
        visited[i][j] = true;
        // up 
        if(i>0 && !visited[i-1][j] && exist(i-1, j, board, word, visited, row, col, index+1)) {
            return true;
        } 
        // down
        if(i<row-1 && !visited[i+1][j] && exist(i+1, j, board, word, visited, row, col, index+1)) {
            return true;
        }
        // left
        if(j>0 && !visited[i][j-1] && exist(i, j-1, board, word, visited, row, col, index+1)) {
            return true;
        }
        // right
        if(j<col-1 && !visited[i][j+1] && exist(i, j+1, board, word, visited, row, col, index+1)) {
            return true;
        }
        // back-tracing 
        // keep in mind to clean the status
        visited[i][j] = false;
        return false;
    }
    
    bool exist(vector<vector<char> > &board, string word) {
        // write your code here
        
        if(board.size() == 0 || board[0].size() == 0) {
            return false;
        }
        if(word.length() == 0) {
            return true;
        }
        
        int row = board.size();
        int col = board[0].size();
        
        vector<vector<bool> > visited(row, vector<bool>(col, false));
        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                if(exist(i, j, board, word, visited, row, col, 0)) {
                    return true;
                }
            }
        }
        return false;        
    }
};