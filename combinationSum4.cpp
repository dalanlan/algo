/*
377. Combination Sum IV
https://leetcode.com/problems/combination-sum-iv/
*/

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> dp(target+1, 0);
        
        
        for(int i=0; i<=target; i++) {
            for(int n:nums) {
                if(n == i) {
                    dp[i]++;
                }
                if(i > n) {
                    dp[i] += dp[i-n];
                }
            }
        }
        return dp[target];
    }
};