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

struct Node {
	int val;
	int index;
	Node(int pVal, int pIndex):val(pVal), index(pIndex){}
};


static bool compare(Node &i,Node &j)
{
	return i.val < j.val; // less than
}

int binarysearch(vector<Node> &ele,int target,int left, int right)
{
	while(left <= right)
	{
		int mid = left + (right-left)/2;
		if(ele[mid].val == target)
			return ele[mid].index;
		else if(ele[mid].val < target)
			left = mid+1;
		else 
			right = mid-1; 
	}
	return -1;
}
vector<int>twoSum(vector<int>& nums,int target){
	vector<Node> ele;

	vector<int> res;
	for(int i=0;i<nums.size();i++)
	{
		ele.push_back(Node(nums[i],i));
	}
	sort(ele.begin(),ele.end(),compare);

	for(int i=0;i<ele.size();i++)
	{
		int resIndex = binarysearch(ele,target-ele[i].val,0,nums.size()-1);
		if(resIndex != -1 && resIndex != ele[i].index)
		{
			res.push_back(min(resIndex,ele[i].index)+1);
			res.push_back(max(resIndex,ele[i].index)+1);
			return res;
		}
	}
	return res;
}    