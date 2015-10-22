// Perfect Squares 


// Solution 1: theory of numbers
int numSquares(int n) {
	
	while(n % 4 == 0)
		n /= 4;
	if(n % 8 == 7)
		return 4;
	for(int a = 0;a*a <= n; a++) {
		int b = sqrt(n- a*a);
		if(a*a + b*b ==n)
			return !!a+!!b;
	}
	return 3;
}

// Solution 2: dynamic programming
int numSquares(int n) {
	
	vector<int> dp(n+1,INT_MAX);
	dp[0] = 0;

	for(int i=0;i<n;i++){
		for(int j=1;i+j*j<=n;j++) {
			dp[i+j*j] = min(dp[i+j*j], dp[i]+1);
		}
	}
	return dp.back();
}