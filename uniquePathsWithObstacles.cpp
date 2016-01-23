
/*
LintCode : unique paths II
http://www.lintcode.com/zh-cn/problem/unique-paths-ii/
*/

class Solution {
public:
    /**
     * @param obstacleGrid: A list of lists of integers
     * @return: An integer
     */ 
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int row = obstacleGrid.size();
        if(row == 0) {
        	return 0;
        }
        int col = obstacleGrid[0].size();

        vector<vector<int>> res(row, vector<int>(col, 0));
        for(int i=0; i<row; i++) {
        	if(obstacleGrid[i][0] == 1) {
        	    break;
        	}
        	res[i][0] = 1;
        }
        for(int i=0; i<col; i++) {
            if(obstacleGrid[0][i] == 1) {
                break;
            }
            res[0][i] = 1;
        }
        
        for(int i=1; i<row; i++) {
        	for(int j=1; j<col; j++) {
        		if(obstacleGrid[i][j] == 1) {
        		    res[i][j] = 0;
        		}
        		else
        			res[i][j] = res[i-1][j] + res[i][j-1];
        		
        	}
        }
        return res[row-1][col-1];
    }
};