
/*
Leetcode: unique paths ii
https://leetcode.com/problems/unique-paths-ii/
*/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        if(obstacleGrid.size() == 0 || obstacleGrid[0].size() == 0) {
            return 0;
        }
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();
        
        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                obstacleGrid[i][j]=1-obstacleGrid[i][j];
            }
        }
        for(int i=1; i<row; i++) {
            obstacleGrid[i][0] = obstacleGrid[i-1][0]==0?0:obstacleGrid[i][0];
        }
        for(int j=1; j<col; j++) {
            obstacleGrid[0][j] = obstacleGrid[0][j-1]==0?0:obstacleGrid[0][j];
        }
        for(int i=1; i<row; i++) {
            for(int j=1; j<col; j++) {
                if(obstacleGrid[i][j] != 0) {
                    obstacleGrid[i][j] = obstacleGrid[i-1][j] + obstacleGrid[i][j-1];
                }
            }
        }
        return obstacleGrid[row-1][col-1];
    }
};