
/*
LeetCode: Maximum Product Subarray
https://leetcode.com/problems/maximum-product-subarray/

Find the contiguous subarray within an array (containing 
at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.
*/


int maxProduct(vector<int>& nums) {
	if(nums.size() == 0) {
		return 0;
	}

	int localMax = nums[0];
	int localMin = localMax, res = localMax;
	for(int i=1; i<nums.size(); i++) {
		int tempMax = localMax;
		localMax = max(max(localMax*nums[i], nums[i]), localMin*nums[i]);
		localMin = min(min(tempMax*nums[i], nums[i]), localMin*nums[i]);
		res = max(localMax, max(localMin, res));
	}
	return res;
}