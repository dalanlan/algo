//backtracking
void permute(vector<int>& nums, vector<vector<int>>& res, int i) {
	
	if(i == nums.size()-1) {
		res.push_back(nums);
	}
	else {
		for(int j=i;j<nums.size();j++) {
			swap(nums[i],nums[j]);
			permute(nums,res,i+1);
			swap(nums[i],nums[j]);
		}
	}

}
vector<vector<int>> permute(vector<int>& nums)
{
	vector<vector<int>> res;

	if(nums.size() == 0)
		return res;
	
	permute(nums,res,0);
	return res;
		
	}
}