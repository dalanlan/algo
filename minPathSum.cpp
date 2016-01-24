
/*
LeetCode : longest substring without repeating characters
https://leetcode.com/problems/longest-substring-without-repeating-characters/
*/

class Solution {
public:
    /**
     * @param grid: a list of lists of integers.
     * @return: An integer, minimizes the sum of all numbers along its path
     */
    int minPathSum(vector<vector<int> > &grid) {
         int row=grid.size();
         if(row == 0) {
            return 0;
         }
         int col = grid[0].size();
         if(col == 0) {
             return 0;
         }
         
         vector<vector<int>> dp(row, vector<int>(col, 0));
         
         dp[0][0] = grid[0][0];
         for(int i=1; i<col; i++) {
             dp[0][i] = grid[0][i];
             dp[0][i] += dp[0][i-1];
         }
         for(int j=1; j<row; j++) {
             dp[j][0] = grid[j][0];
             dp[j][0] += dp[j-1][0];
         }
         
         for(int i=1; i<row; i++) {
             for(int j=1; j<col; j++) {
                 dp[i][j] = grid[i][j];
                 dp[i][j] = min(dp[i][j] + dp[i-1][j], dp[i][j] + dp[i][j-1]);
             }
         }
         return dp[row-1][col-1];
    }
};
