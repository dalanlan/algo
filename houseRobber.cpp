
/*
LintCode: house robber
http://www.lintcode.com/zh-cn/problem/house-robber/
*/


    /**
     * @param A: An array of non-negative integers.
     * return: The maximum amount of money you can rob tonight
     */

     // time:O(n)
     // space: O(n)
    long long houseRobber(vector<int> A) {
        // write your code here
        int sz = A.size();
        if(sz == 0) {
            return 0;
        }
        vector<long long> dp(sz, 0);
        dp[0] = A[0];
        for(int i=1; i<sz; i++) {
            dp[i] = max(dp[i-1], i>=2?dp[i-2]+A[i]:A[i]);
        }
        return dp[sz-1];
    }

// time: O(n)
// space: O(1)
    long long houseRobber(vector<int> A) {
    	int sz = A.size();
    	if(sz == 0) {
    		return 0;
    	}
    	if(sz == 1) {
    		return A[0];
    	}

    	long long prev = A[0];
    	long long cur = max(A[0], A[1]);
    	long long res = cur;
    	for(int i=2; i<sz; i++) {
    		res = max(cur, prev+A[i]);
    		prev = cur;
    		cur = res;
    	}
    	return res;

    }