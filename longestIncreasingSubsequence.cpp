
/*
LintCode : Longest increasing subsequence
http://www.lintcode.com/zh-cn/problem/longest-increasing-subsequence/

Given an array of integer, find out the longest increasing 
subsequence, return the length of LIS.
*/


class Solution {
public:
    /**
     * @param nums: The integer array
     * @return: The length of LIS (longest increasing subsequence)
     */
    int longestIncreasingSubsequence(vector<int> nums) {
        int sz = nums.size();
        if(sz <= 1) {
        	return sz;
        }
        int res=1;
        vector<int> dp(sz,1);

        for(int i=0; i<sz;i++) {
        	for(int j=0; j<i; j++) {
        		if(nums[j] <= nums[i]) {
        			dp[i] = max(dp[i], dp[j]+1);
        			res=max(res, dp[i]);
        		}
        	}
        }
        return res;
    }
};
