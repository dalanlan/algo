
/*
LintCode 39: Remove rotated sorted array
*/


void recoverRotatedSortedArray(vector<int> &nums) {
	for(int i=0; i<nums.size()-1; i++) {
		if(nums[i] > nums[i+1]) {
			reverse(nums.begin(), nums.begin()+i+1);
			reverse(nums.begin()+i+1, nums.end());
			reverse(nums.begin(), nums.end());
		}
	}
}

