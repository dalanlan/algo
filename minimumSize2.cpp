
/*
LintCode: minimum size subarray sum

*/

int minimumSize(vector<int> &nums, int s) {
	int res = INT_MAX;
	int start=0, end=0, sum = 0;
	int sz = nums.size();
	while(start < sz && end < sz) {
		sum += nums[end++];

		while(sum >= s) {
			res = min(res, end-start);
			sum -= nums[start++];
		}
	}
	return res==INT_MAX?-1:res;
}