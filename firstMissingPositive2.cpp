

/*
LeetCode: First Missing Positive
https://leetcode.com/problems/first-missing-positive/
*/
int firstMissingPositive(vector<int>& nums) {
	for(int i=0; i<nums.size(); i++) {
		while(nums[i] - 1 >= 0 && nums[i] != i+1 && nums[i] <= nums.size()) {
			if(nums[i] == nums[nums[i]-1]) {
			    break;
			}
			swap(nums[i], nums[nums[i] - 1]);
		}

	}
	for(int i=0; i<nums.size(); i++) {
		if(nums[i]  != i+1) {
			return i+1;
		}
	}
	return nums.size()+1;
}