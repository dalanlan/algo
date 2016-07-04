/*
Geeks for Geeks:
Given an array arr[], find the maximum j – i such that arr[j] > arr[i]

http://www.geeksforgeeks.org/given-an-array-arr-find-the-maximum-j-i-such-that-arrj-arri/
*/

// solution 1: brute force
// O(n^2)
int maxDiff(vector<int> nums) {
	if(nums.size() < 2) {
		return -1;
	}

	int res = -1;
	for(int i=0; i<nums.size(); i++) {
		for(int j=i+1; j<nums.size(); j++) {
			if(nums[j] > nums[i]) {
				res = max(res, j-i);
			}
		}
	}
	return res;
}

// solution 2:

int maxDiff(vector<int> nums) {
	int sz = nums.size();
	if(sz < 2) {
		return -1;
	}
	// construct LMin
	vector<int> LMin(sz, INT_MAX);
	LMin[0] = nums[0];
	for(int i=1; i<sz; i++) {
		LMin[i]=min(LMin[i-1], nums[i]);
	}

	// connstruct RMax;
	vector<int> RMax(sz, INT_MIN);
	RMax[sz-1] = nums[sz-1];
	for(int i=sz-2; i>=0; i--) {
		RMax[i] = max(RMax[i+1], nums[i]);
	}

	// get the result
	int res = -1;
	int i=0, j=0;
	while(i<sz && j < sz) {
		if(LMin[i] < RMax[j]) {
			res = max(res, j-i);
			j++;
		}
		else {
			i++;
		}
	}
	return res;
}