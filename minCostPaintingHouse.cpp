
/*
Painting house: Facebook interview
There are a row of houses, each house can be painted with three colors, 
red, blue and green. The cost of painting each house with a certain color
is different. You have to paint all the houses such that no two adjacent
houses have the same color. You have to paint the houses with minimum cost.
How would you do it?
Note: Painting house-1 with red costs different painting house-2 with red.
The cost are different for each house and each color.
*/

// cost[0~m-1][0~n-1]
// m: color
// n: house
int minCostPaintingHouse(int n, int m, vector<vector<int>>& cost) {
	
	//dp[i][j]: min cost to paint house i with color j
	vector<vector<int>> dp=vector<vector<int>>(n+1, vector<int>(m, INT_MAX));

	for(int i=0; i<=m; i++) {
		dp[0][i] = 0;
	}

	for(int i=1; i<=n; i++) {
		for(int j=0; j<m; j++) {
			for(int k=0; k<m; k++) {
				if(k==j) {
					continue;
				}
				dp[i][j] = min(dp[i][j], dp[i-1][k]+cost[i-1][j]);
			}
		}
	}
	int res = INT_MAX;
	for(int i=0; i<m; i++) {
		res = min(res, dp[n][i]);
	}
	return res;
}