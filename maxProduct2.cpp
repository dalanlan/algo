
/*
LeetCode: maximum product subarray
https://leetcode.com/problems/maximum-product-subarray/
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 0) {
            return 0;
        }
        int maxSuffix = nums[0], minSuffix = nums[0];
        int res = nums[0];
        
        for(int i=1; i<nums.size();i++) {
            int tmpMax = maxSuffix;
            maxSuffix = max(maxSuffix*nums[i], max(nums[i], minSuffix*nums[i]));
            minSuffix = min(minSuffix*nums[i], min(nums[i], tmpMax*nums[i]));
            res = max(res, max(maxSuffix, minSuffix));
        }
        return res;
    }
};