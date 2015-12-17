// Permutations
/*
Given a collection of numbers, return all possible permutations.
For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1],[3,1,2] and [3,2,1].
*/

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


void permute(vector<vector<int> >& res, vector<int>& nums, int index) {
	if(index == nums.size()-1) {
		res.push_back(nums);
	}
	for(int i=index; i<nums.size();i++) {
		swap(nums[index], nums[i]);
		permute(res, nums, index+1);
		swap(nums[index], nums[i]);
	}
	
}
vector<vector<int> > permute(vector<int>& nums) {
	vector<vector<int> > res;
	if(nums.size() == 0) {
		return res;
	}

	permute(res, nums, 0);
	return res;
}