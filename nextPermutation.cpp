// Next Permutation

//Solution 1: lazy solution
void nextPermutation(vector<int>& nums) {
	next_permutation(nums.begin(),nums.end());
}

//Solution 2:
void nextPermutation(vector<int>& nums) {

	int j=nums.size()-2, k=nums.size()-1;

	while(j >= 0 && nums[j] >= nums[j+1]) j--;

	if(j == -1) {
		reverse(nums.begin(),nums.end());
		return;
	}

	while(k >= j && nums[k] <= nums[j]) k--;

	swap(nums[j],nums[k]);
	reverse(nums.begin()+j+1,nums.end());

	return;
}

//Solution 3: just like Solution 2
void nextPermutation(vector<int>& nums) {
	int j=nums.size()-2,k=nums.size()-1;

	for(;j>=0;j--) {
		if(nums[j] < nums[j+1])
			break;
	}

	if(j == -1)
	{
		reverse(nums.begin(),nums.end());
		return;
	}

	for(;k >= j;k--) {
		if(nums[k] > nums[j])
			break;
	}
	swap(nums[j],nums[k]);
	reverse(nums.begin()+j+1,nums.end());
	return;
}
