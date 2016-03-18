
/*
LeetCode: product of array except self
https://leetcode.com/problems/product-of-array-except-self/
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        vector<int> product(nums.size(), 1);
        int left = 1;
        for(int i=1; i<nums.size(); i++) {
            left *= nums[i-1];
            product[i] *= left;
        }
        int right = 1;
        for(int i=nums.size()-2; i>=0; i--) {
            right *= nums[i+1];
            product[i] *= right;
        }
        return product;
    }
};