
/*
LeetCode: dungeon game
https://leetcode.com/problems/dungeon-game/
*/

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        
        if(dungeon.size() == 0 || dungeon[0].size() == 0) {
            return 1;
        }
        int row = dungeon.size();
        int col = dungeon[0].size();
        
        //calculate supplyment
       vector<vector<int>> dp(row+1, vector<int>(col+1, INT_MAX));
       dp[row][col-1] = 1;
       dp[row-1][col] = 1;
       for(int i=row-1; i>=0; i--) {
           for(int j=col-1; j>=0; j--) {
               int need = min(dp[i+1][j], dp[i][j+1]) - dungeon[i][j];
               dp[i][j] = need>0?need:1;
           }
        }
        return dp[0][0];
       
    }
};