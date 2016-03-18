
/*
LeetCode: max subarray
https://leetcode.com/problems/maximum-subarray/
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0) {
            return 0;
        }
        int suffix = nums[0];
        int res = nums[0];
        
        for(int i=1; i<nums.size(); i++) {
            suffix = max(suffix+nums[i], nums[i]);
            res = max(res, suffix);
        }
        return res;
    }
};