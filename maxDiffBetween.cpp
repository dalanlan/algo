/*
GeeksforGeerk:
http://www.geeksforgeeks.org/maximum-difference-between-two-elements/

Given an array arr[] of integers, find out the difference between any two elements such that larger element appears after the smaller number in arr[].

Examples: If array is [2, 3, 10, 6, 4, 8, 1] then returned value should be 8 (Diff between 10 and 2). If array is [ 7, 9, 5, 6, 3, 2 ] then returned value should be 2 (Diff between 7 and 9)

*/

// solution 1: track local min value from left
int maxDiff(vector<int> nums) {
	if(nums.size() < 2) {
		return -1;
	}
	int res = nums[1]-nums[0];
	int minLocal = nums[0];
	for(int i=1; i<nums.size(); i++) {
		res = max(res, nums[i] - minLocal);
		minLocal = min(minLocal, nums[i]);
	}
	return res;
}

// solution 2: track local max from right
int maxDiff(vector<int> nums) {
	if(nums.size() < 2) {
		return -1;
	}
	int sz = nums.size();
	int res = nums[sz-1] - nums[sz-2];
	int maxLocal = nums[sz-1];
	for(int i=sz-2; i>=0; i--) {
		res = max(res, maxLocal - nums[i]);
		maxLocal = max(maxLocal, nums[i]);
	}
	return res;
}

