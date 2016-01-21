
/*
LintCode : Smallest subarray
Given an array of integers, find the subarray with smallest sum.
Return the sum of the subarray.

Given[1, -1, -2, 1]，return -3
*/


class Solution {
public:
    /**
     * @param nums: a list of integers
     * @return: A integer denote the sum of minimum subarray
     */
    int minSubArray(vector<int> nums) {
    	int sz = nums.size();
    	if(sz == 0) {
    		return 0;
    	}
	 	int min = nums[0], suffix = nums[0];
	 	for(int i=1; i<sz; i++) {
	 		if(suffix+nums[i] < nums[i]) {
	 			suffix += nums[i];
	 		}
	 		else {
	 			suffix = nums[i];
	 		}

	 		if(suffix < min) {
	 			min = suffix;
	 		}

	 	}
	 	return min;
	 	}
};
