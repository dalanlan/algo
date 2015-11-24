// Longest increasing subsequence

// Solution 1: TLE
// http://www.geeksforgeeks.org/dynamic-programming-set-3-longest-increasing-subsequence/
// I believe the wrapper function `lis` is useless

int lengthOfLIS(vector<int>& nums) {
	if(nums.size() <= 1) {
		return nums.size();
	}

	
	lis(nums, nums.size());

} 

int lis(vector<int>& nums, int sz) {
	int max = 1;
	helper(nums, sz, max);
	return max;

}

int helper(vector<int>& nums, int sz, int& max) {
	
	
	if(sz == 1) {
		return 1;
	}

	int res, maxEnd = 1;

	for(int i = 1; i< sz; i++) {
		res = helper(nums, i, max);

		if(nums[i-1] < nums[sz-1] && res + 1 > maxEnd) {
			maxEnd = res + 1;
		}
	}
	if(maxEnd > max) {
		max = maxEnd;
	}
	return maxEnd;

}

// dynamic programming

int lengthOfLIS(vector<int> &nums) {
	int sz = nums.size(); 
	if(sz <= 1) {
		return sz;
	}
	int *dp = new int[sz];
	int maxVal = 1;

	for(int i = 0; i < sz; i++) {
		dp[i] = 1;
		for(int j = 0; j < i; j++) {
			if(nums[j] < nums[i]) {
				dp[i] = max(dp[i], dp[j] +1);
				maxVal = max(dp[i], maxVal);
			}
		}
	}
	return maxVal;
}

// conduct binary search???
// lower bound??
/*
lower_bound: returns an iterator pointing to the first element 
in the range [first,last) which does not compare less than val.
the first >=  val
*/

// upper bound
/*
upper_bound: returns an iterator pointing to the first element 
in the range [first,last) which compares greater than val.
the first > val
*/

// Using lower_bound and upper_bound to gain a binary search 

int lengthOfLIS(vector<int>& nums) {
	if(nums.size() == 0) {
		return nums.size();
	}
	vector<int> tail;

	for(int i=0; i< nums.size();i++) {
		int n = nums[i];
		// *iter points to the first element >= n
		auto iter = lower_bound(tail.begin(), tail.end(), n); 
		// the new element is greater than the max val of tail 
		if(iter == tail.end()) {
			tail.push_back(n);
		}
		// update the not-so-long list 
		else {
			*iter = n;
		}

	}
	return tail.size();
}