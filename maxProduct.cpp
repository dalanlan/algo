
/*
LintCode: Maximum product subarray
Fing out the continous subsequence of a given
array.

http://www.lintcode.com/zh-cn/problem/maximum-product-subarray/
*/


class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: an integer
     */
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 0) {
        	return 0;
        }
        int maxx = nums[0];
        int minn = nums[0];
        int res = nums[0];
        int tmpMax, tmpMin;
        for(int i=1; i<nums.size();i++) {
            tmpMax = maxx;
            tmpMin = minn;
        	maxx = max(max(tmpMax*nums[i], tmpMin*nums[i]),nums[i]);
        	minn = min(min(tmpMax*nums[i], tmpMin*nums[i]),nums[i]);
        	res = max(maxx, res);
        } 
        return res;
    }
};