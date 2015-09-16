//Two Sum
// Index is one-based


// Sol1 brute force : time limit exceeded
vector<int> twoSum(vector<int>& nums,int target){
	vector<int> res;
	if(nums.size()==0)
		return res;

	for(int i=0;i<nums.size();i++)
	{
		for(int j = i+1;j<nums.size();j++)
			if(nums[i]+nums[j]==target)
			{
				res.push_back(i+1);
				res.push_back(j+1);
			}	
	}
	return res;
}

// Sol2: Use a map

vector<int>twoSum(vector<int>& nums,int target){
	vector<int>res;
	map<int,int> mp;
	if(nums.size()==0)
		return res;

	for(int i=0;i<nums.size();i++)
	{
		mp[nums[i]] = i;
	}
	map<int,int>::iterator it;
	for(int i=0;i<nums.size();i++)
	{
		it = mp.find(target-nums[i]);
		if(it != mp.end() && it ->second !=i)
		{
			res.push_back(min(it->second,i)+1);
			res.push_back(max(it->second,i)+1);
			return res;
		}
	}
}

//Sol3: sort + binarysearch
