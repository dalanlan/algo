
/*
LeetCode: Jump Game II
https://leetcode.com/problems/jump-game-ii/
*/

// TLE
int jump(vector<int>& nums) {
	vector<int> dp(nums.size(), INT_MAX);
	dp[0] = 0;

	for(int i=1; i<nums.size(); i++) {
		for(int j=0; j<i; j++) {
			if(nums[i] >= i-j) {
				dp[i] = min(dp[i], dp[j]+1);
			}
		}
	}
	return dp[nums.size()-1];
}

// try another way
// bfs
int jump(vector<int>& nums) {
        int sz = nums.size();
        if(sz < 2) {
            return 0;
        }
        int i=0, jump=0, maxCur=0, maxNext=0;
        while(maxCur-i+1>0) {
            
            jump++;
            for(;i<=maxCur;i++) {
                maxNext = max(maxNext, nums[i]+i);
                if(maxNext >= sz-1) {
                    return jump;
                }
            }
            maxCur = maxNext;
        }
        return jump;
    }