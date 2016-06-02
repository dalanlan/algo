// Maximal Square

/*
Given a 2D binary matrix filled with 0's and 1's, 
find the largest square containing all 1's and 
return its area.
*/


int maximalSquare(vector<vector<char>>& matrix) {
	int row = matrix.size();
	if(row == 0) {
		return 0;
	}
	int col = matrix[0].size();
	vector<vector<int>> m(row+1, vector<int>(col+1, 0));
	int maxV = 0;

	// to handle corner cases (i == 0 or j == 0)
	for(int i = 1; i <= row; i++) {
		for(int j = 1; j <= col; j++) {
			if(matrix[i-1][j-1] == '0') {
				m[i][j] = 0;
			}
			else {
				m[i][j] = min(min(m[i][j-1], m[i-1][j]), m[i-1][j-1]) + 1;
				maxV = max(maxV, m[i][j]);
			}
		}
	}
	return maxV*maxV;

}


class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0) {
            return 0;
        }
        int row = matrix.size();
        int col = matrix[0].size();
        
        // this is excellent
        // use an extra col and extra row to deal with the corner case
        // vector<vector<int>> dp(row+1, vector<int>(col+1, 0));
        
        // int res = 0;
        // for(int i=1; i<=row; i++) {
        //     for(int j=1; j<=col; j++) {
        //         if(matrix[i-1][j-1] == '0') {
        //             dp[i][j] = 0;
        //         }    
        //         else {
        //             dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]),dp[i-1][j-1])+1;
        //             res = max(res, dp[i][j]);
        //         }
        //     }
        // }
        vector<vector<int>> dp(row, vector<int>(col, INT_MAX));
        int res = 0;
        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                if(matrix[i][j] == '0') {
                    dp[i][j] = 0;
                }
                else {
                	// or you must deal with corner cases yourself
                	// which is stupid
                    dp[i][j] = min(dp[i][j], i>0?dp[i-1][j]:0);
                    dp[i][j] = min(dp[i][j], j>0?dp[i][j-1]:0);
                    dp[i][j] = min(dp[i][j], i>0&&j>0?dp[i-1][j-1]:0);
                    dp[i][j]++;
                    res = max(res, dp[i][j]);
                }
            }
        }
        return res*res;
    }
};