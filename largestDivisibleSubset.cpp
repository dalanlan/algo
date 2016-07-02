/*
Leetcode: largest divisible subset
https://leetcode.com/problems/largest-divisible-subset/

Given a set of distinct positive integers, find the largest subset 
such that every pair (Si, Sj) of elements in this subset satisfies: Si % Sj = 0 or Sj % Si = 0.

If there are multiple solutions, return any subset is fine.


*/

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int sz = nums.size();
        vector<int> dp(sz, 0);
        vector<int> parent(sz, 0);
        
        int res = 0;
        int index = 0;
        for(int i=sz-1; i>=0; i--) {
            for(int j=i; j<sz; j++) {
                if(nums[j] % nums[i] == 0 && dp[i] < dp[j]+1) {
                    dp[i] = dp[j]+1;
                    parent[i] = j;
                     if(dp[i]>res) {
                        res = dp[i];
                        index = i;
                    }
                }
                
            }
           
        }
        vector<int> ans;
        
        for(int i=0; i<res; i++) {
            ans.push_back(nums[index]);
            index = parent[index];
        }
        return ans;

    }
};