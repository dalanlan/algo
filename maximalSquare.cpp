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