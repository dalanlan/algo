//Solution 1: Use a set. TLE
void permute(vector<int>& nums, set<vector<int>>& resSet, int index) {
	
	if(index == nums.size()-1)
		resSet.insert(nums);

	else for(int j=index;j<nums.size();j++) {
		swap(nums[index],nums[j]);
		permute(nums,resSet,index+1);
		swap(nums[index],nums[j]);
	}
}
vector<vector<int>> permuteUnique(vector<int>& nums) {
	vector<vector<int>> res;
	if(nums.size() == 0)
		return res;

	set<vector<int>> resSet;

	permute(nums, resSet, 0);
	set<vector<int>>::iterator it;
	
	for(it = resSet.begin(); it != resSet.end(); it++)
		res.push_back(*it);
	return res;
}

// Solution 2: Wrooooong!!!!
/*void permute(vector<int>& nums, vector<vector<int>>& res, int i) {
	
	if(i == nums.size()-1) {
		res.push_back(nums);
	}
	else {
		for(int j=i;j<nums.size();j++) {
			if(i != j && nums[i] == nums[j])
				continue;
			swap(nums[i],nums[j]);
			permute(nums,res,i+1);
			swap(nums[i],nums[j]);
		}
	}

}
vector<vector<int>> permuteUnique(vector<int>& nums)
{

	vector<vector<int>> res;

	if(nums.size() == 0)
		return res;
	sort(nums.begin(),nums.end());
	permute(nums,res,0);
	return res;
		
	
}*/

// Solution 3: Use extra space to record whether it has been used or not

vector<vector<int>> permuteUnique(vector<int>& nums) {
	vector<vector<int>> res;

	if(nums.size() == 0)
		return res;
	sort(nums.begin(),nums.end());
	std::vector<int> resEle;
	vector<int> used(nums.size(),0);

	dfs(nums,resEle,used,res);
	return res;
}

void dfs(vector<int>& nums, vector<int>& resEle, vector<int>& used, vector<vector<int>>& res) {
	if(resEle.size() == nums.size()) {
		res.push_back(resEle);
		return;
	}
		
	else {
		for(int i=0; i < nums.size(); i++) {
			if(used[i] || (i>0 && nums[i] == nums[i-1] && used[i-1])) {
				continue;
			}
			used[i] = 1;
			resEle.push_back(nums[i]);
			dfs(nums,resEle,used,res);
			used[i] = 0;
			resEle.pop_back();
		}
	}
}
