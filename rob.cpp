
/*
Leetcode: house robber
https://leetcode.com/problems/house-robber/
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0) {
            return 0;
        }
        vector<int> dp(nums.size()+1, 0);
        dp[0] = 0;
        for(int i=1; i<=nums.size(); i++) {
            if(i == 1) {
                dp[i] = nums[0];
            }
            else if(nums[i-1]+dp[i-2] > dp[i-1]) {
                dp[i] = dp[i-2] + nums[i-1];
            }
            else {
                dp[i] = dp[i-1];
            }
        }
        return dp[nums.size()];
    }
};

// no need for extra array space
    long long houseRobber(vector<int> A) {
        long long exclude=0, include=0;
        
        for(int i=0; i<A.size(); i++) {
            long long exc = exclude, inc = include;
            include = exc + A[i];
            exclude = max(exc, inc);
        }
        return max(include, exclude);
    }
    