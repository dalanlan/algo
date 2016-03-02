
/*
LintCode: maximum subarray ii
http://www.lintcode.com/zh-cn/problem/maximum-subarray-ii/
*/

int maxTwoSubArrays(vector<int> nums) {
	
	int sz = nums.size();
	if(sz < 2) {
		return INT_MIN;
	}

	vector<int> left(sz, 0);
	left[0] = nums[0];
	int globalMax=nums[0], localMax=nums[0];
	
	for(int i=1; i<sz; i++) {
		localMax = max(localMax+nums[i], nums[i]);
		globalMax = max(localMax, globalMax);
		left[i] = globalMax;
	}

	int res = INT_MIN;
	localMax = nums[sz-1];
	for(int i=sz-2; i>=0; i--) {
		res = max(res, localMax + left[i]);
		localMax = max(localMax+nums[i], nums[i]);
	}
	return res;
}