// 3Sum Closest

/*
Given an array S of n integers, find three integers
in S such that the sum is closest to a given number,
target. Return the sum of the three integers. You may
assume that each input would have exactly one solution.
*/


vector<vector<int>> threeSum(vector<int>& nums, int target) {
	vector<vector<int> > res;

	sort(nums.begin(), nums.end());
	for(int i=0; i < nums.size();i++) {
		if(i > 0 && nums[i] == nums[i-1]) {
			continue;
		}
		twoSum(nums, i+1, res, target-nums[i], nums[i]);
	}
}

int threeSumClosest(vector<int>& nums, int target) {
	if(nums.size() < 3) {
		return 0;
	}
	sort(nums.begin(), nums.end());
	int mini = nums[0]+nums[1]+nums[2];
	for(int i=0;i<nums.size()-2;i++) {
		if(i > 0 && nums[i] == nums[i-1]) {
			continue;
		}
        
		int twoSum = twoSumClosest(nums, i+1, target-nums[i]);
		
		if(abs(target-(nums[i]+twoSum)) < abs(target - mini)) {
			mini = nums[i] + twoSum;
		}
		if(target == mini) {
		    break;
		}
	}
	return mini;
}

//return the closest sum of two nums
int twoSumClosest(vector<int>& nums, int index, int target) {
	
	int lo = index, hi = nums.size()-1;
	int mini = nums[lo]+nums[hi];
   
	while(lo < hi) {
		if(abs(target - (nums[lo] + nums[hi])) < abs(mini - target)) {
			mini = nums[lo] + nums[hi];
		}
		if(nums[lo] + nums[hi] > target) {
			hi--;
		}
		else if(nums[lo] + nums[hi] < target) {
			lo++;
		}
		else {
			break;
		}
		
	}
	return mini;

}