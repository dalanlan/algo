
/*

LintCode : Maximum subarray difference
http://www.lintcode.com/zh-cn/problem/maximum-subarray-difference/
*/

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: An integer indicate the value of maximum difference between two
     *          Subarrays
     */
    int maxDiffSubArrays(vector<int> nums) {
        int sz = nums.size();
        if(sz < 2) {
        	return 0;
        }

        vector<int> leftMax(sz, 0);
        vector<int> leftMin(sz, 0);
        leftMax[0] = leftMin[0] = nums[0];
        int leftMx = nums[0];
        int leftMn = nums[0];
        for(int i=1; i<sz; i++) {
        	leftMax[i] = max(leftMax[i-1]+nums[i], nums[i]); 
        	leftMin[i] = min(leftMin[i-1]+nums[i], nums[i]);
        }
        for(int i=1; i<sz; i++) {
        	if(leftMx > leftMax[i]) {
        		leftMax[i] = leftMx;
        	} 
        	else {
        		leftMx = leftMax[i];
        	}
        	if(leftMn < leftMin[i]) {
        		leftMin[i] = leftMn;
        	}
        	else {
        		leftMn = leftMin[i];
        	}
        }

        
        vector<int> rightMax(sz, 0);
        vector<int> rightMin(sz, 0);
        rightMax[sz-1] = rightMin[sz-1] = nums[sz-1];
        int rightMx = nums[sz-1];
        int rightMn = nums[sz-1];

        for(int i=sz-2; i>=0; i--) {
        	rightMax[i] = max(rightMax[i+1]+nums[i], nums[i]);
        	rightMin[i] = min(rightMin[i+1]+nums[i], nums[i]);
        }
        for(int i=sz-2; i>=0; i--) {
        	if(rightMx > rightMax[i]) {
        		rightMax[i] = rightMx;
        	}
        	else {
        		rightMx = rightMax[i] ;
        	}
        	if(rightMn < rightMin[i]) {
        		rightMin[i] = rightMn;
        	}
        	else {
        		rightMn = rightMin[i];
        	}
        }

        
        int res = INT_MIN;
        for(int i=0; i<sz-1; i++) {
        	res = max(res, abs(leftMax[i]-rightMin[i+1]));
        }
        for(int i=sz-1; i>0; i--) {
        	res = max(res, abs(rightMax[i]-leftMin[i-1]));
        }
        return res;
    }
};
