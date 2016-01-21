
/*
LintCode : Max sub array
Given an array of integers, find out a sub array 
with max sum, return the sum of the sub array.
*/

class Solution {
public:    
    /**
     * @param nums: A list of integers
     * @return: A integer indicate the sum of max subarray
     */
    int maxSubArray(vector<int> nums) {
        int sz = nums.size();
        if(sz == 0) {
        	return 0;
        }
        int suffix = nums[0];
        int max = nums[0];

        for(int i=1;i<sz;i++) {
        	if(suffix + nums[i] > nums[i]) {
        		suffix += nums[i];
        	}
        	else {
        		suffix = nums[i];
        	}
        	if(suffix > max) {
        		max = suffix;
        	}
        }
        return max;
    }
};
