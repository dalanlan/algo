

/*
Leetcode: paint fence
There is a fence with n posts, each post can be painted with one of the k colors.
You have to paint all the posts such that no more than two adjacent fences posts
have the same color. Return the total number of ways you can paint the fence.

*/

// n: fences
// k: colors
int numWays(int n, int k) {

}


// dp[i]: different ways of paiting 

int numWays(int n, int k) {
	vector<int> dp(n+1, 0);
	dp[1]=k;
	dp[2]=k*k;
	if(n <= 2) {
		return dp[n];
	}
	for(int i=3;i<=n;i++) {
		dp[i] = dp[i-1]*(k-1) + dp[i-2]*(k-1);
	}
	return dp[n];
}
