
/*
LintCode : Max two subarrays
http://www.lintcode.com/zh-cn/problem/maximum-subarray-ii/


Given an array of integers, find two non-overlapping subarrays which have the largest sum.
The number in each subarray should be contiguous.
Return the largest sum.
*/

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: An integer denotes the sum of max two non-overlapping subarrays
     */
    int maxTwoSubArrays(vector<int> nums) {
        int sz = nums.size();
        if(sz < 2) {
        	return INT_MIN;
        }

      	vector<int> left(sz, 0);
      	int maxLeft = nums[0];
      	left[0] = nums[0];

      	for(int i=1; i<sz; i++) {
      		left[i] = max(left[i-1]+nums[i], nums[i]);
      	}
      	for(int i=1; i<sz; i++) {
      	    if(left[i] > maxLeft) {
      			maxLeft = left[i];
      		}
      		else {
      			left[i] = maxLeft;
      		}
      	}
       	
      	vector<int> right(sz, 0);
      	int maxRight = nums[sz-1];
      	right[sz-1] = nums[sz-1];
 
      	for(int i=sz-2; i>=0; i--) {
      		right[i] = max(right[i+1] + nums[i], nums[i]);
      	}
      	
      	for(int i=sz-2; i>=0; i--) {
      	    if(right[i] > maxRight) {
      		    	maxRight = right[i];
      		}
      		else {
      			right[i] = maxRight;
      	    }
      	}
      		
      	
       	
      	int res = INT_MIN;
      	for(int i=0;i<sz-1;i++) {
      		res = max(res, left[i] + right[i+1]);
      	}
      	return res;
    }
};
