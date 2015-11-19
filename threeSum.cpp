// 3Sum

    void twoSum(vector<int>& nums, vector<vector<int>>& res, int index, int target, int prev) {
	// need two values
	if (index >= nums.size()-1)
		return;

	int lo=index, hi=nums.size()-1, sum;
	vector<int> path;
	while(lo<hi) {
		sum = nums[lo] + nums[hi];
		if(sum == target){
		   
			path.push_back(prev);
			path.push_back(nums[lo]);
			path.push_back(nums[hi]);
			res.push_back(path);
			path.clear();
			while(lo+1<nums.size() && nums[lo] == nums[lo+1])lo++;
		    while(hi-1>=0 && nums[hi-1] == nums[hi])hi--;
		}

		if(sum > target) hi--;
		else lo++;
	

	}

}
vector<vector<int>> threeSum(vector<int>& nums) {
	vector<vector<int>> res;
	if(nums.size() < 3)
		return res;

	sort(nums.begin(), nums.end());

	int cur;
	for(int i=0;i<nums.size();i++) {
		cur = nums[i];
		if(i>0 && nums[i] == nums[i-1]) {
			continue;
		}

		twoSum(nums, res, i+1, 0-cur, cur);
		
	}
	return res;
}