
/*
LeetCode: 3Sum
https://leetcode.com/problems/3sum/
*/

void twoSum(vector<vector<int>>& res, vector<int>& nums, int elem, int target, int index) {
	int lo = index, hi = nums.size()-1;

	while(lo < hi) {
	    int sum = nums[lo] + nums[hi];
		if(sum == target) {
			res.push_back({elem, nums[lo], nums[hi]});
			do {
				lo++;
			} while(lo < hi && nums[lo] == nums[lo-1]);
			do {
				hi--;
			} while(lo < hi && nums[hi] == nums[hi+1]);
		}
		else if(sum < target) {
		    lo++;
		}
		else {
		    hi--;
		}
	}
}
vector<vector<int>> threeSum(vector<int>& nums) {
	sort(nums.begin(), nums.end());

	vector<vector<int>> res;
    if(nums.size() < 3) {
        return res;
    }
	for(int i=0; i<nums.size()-2; i++) {
		if(i>0 && nums[i] == nums[i-1]) {
			continue;
		}
		twoSum(res, nums, nums[i], -nums[i], i+1);
	}
	return res;
}