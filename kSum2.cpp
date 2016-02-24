
/*
LintCode: k sum 
http://www.lintcode.com/zh-cn/problem/k-sum/#

*/

// solution :dp
// dp[i][j][t]: how many methods to achive t with j numbers in 0~i-1th in A 
      int kSum(vector<int> A, int k, int target) {
        if(target < 0) {
            return 0;
        }
        int sz = A.size();
        int dp[sz+1][k+1][target+1];

        for(int i=0; i<=sz; i++) {
            for(int j=0; j<=k; j++) {
                for(int m=0; m<=target;m++) {
                    dp[i][j][m] = 0;
                    if (j==0 && m == 0) {
                        dp[i][j][m] = 1;
                    }
                    else if(i > 0) {
                        dp[i][j][m] = dp[i-1][j][m];
                        if(j > 0 && m >= A[i-1]) {
                            dp[i][j][m] += dp[i-1][j-1][m-A[i-1]];
                        }
                    }
                }
            }
        }

        return dp[sz][k][target];
    }

      int kSum(vector<int> A, int k,  int target) {
    	int sz = A.size();
    	int dp[k+1][target+1];
    	for(int i=0; i<=k; i++) {
    	    for(int t=0; t<=target; t++) {
    	        dp[i][t] = 0;
    	    }
    	}
    	dp[0][0] = 1;
    	for(int i=1; i<=sz; i++) {
    		for(int t = target; t>=0; t--) {
    			for(int j = 1; j<=k; j++) {
    				if(t >= A[i-1]) {
    					dp[j][t] += dp[j-1][t-A[i-1]];
    				}
    			}
    		}
    	}
    	return dp[k][target];

    }