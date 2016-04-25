
/*
2016/04/24
LeetCode: paint fence

There is a fence with n posts, each post can be painted with one of the k colors.

You have to paint all the posts such that no more than two adjacent fence posts have the same color.

Return the total number of ways you can paint the fence.

Note:
n and k are non-negative integers.

Tags: Dynamic Programming
Similar Problems: (E) House Robber, (M) House Robber II, (M) Paint House, (H) Paint House II

*/

/*
This one is extremely easy as of fact.
 says we have 1~n posts
S(n) = D(n-1)
D(n) = (k-1)*[D(n-1) + S(n-1)]
T(n)	= S(n) + D(n) 
	= D(n-1) + (k-1)*T(n-1)
	= (k-1)*[D(n-2) + S(n-2)] + (k-1) *T(n-1)
	=(k-1) * [T(n-2) + T(n-1)];

This is gonna stands for n>=3

for n == 0, 0
for n == 1, k
for k == 0, 0
*/

int numWays (int n, int k) {
	if(n <= 1 || k <= 0) {
		return n*k;
	}

	vector<int> dp(n+1, 0);
	dp[0] = 0;
	dp[1] = k;
	dp[2] = k+k*(k-1);
	for(int i=3; i<=n; i++) {
		dp[i] = (k-1)*(dp[i-1] + dp[i-2]);
	}
	return dp[n];


}















