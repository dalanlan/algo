#include <iostream>
#include <vector> 
#include <algorithm>
#include <unordered_map>

using namespace std;

bool containsDuplicate(vector<int>& nums)
{
	unordered_map<int,int> mp;
	for(int i =0;i<nums.size();i++)
	{
		if(mp.find(nums[i]) == mp.end())
			mp[nums[i]] = i;
		else
			return true;
	}
	return false;
	
}
bool containsNearbyDuplicate(std::vector<int>nums, int k)
{
	unordered_map<int,int> mp;

	for (int i = 0; i < nums.size(); ++i)
	{
		if(mp.find(nums[i])==mp.end())
		{
			mp[nums[i]] = i;
		}
		else
		{
			if(i-mp[nums[i]] <=k)
				return true;
			else
				mp[nums[i]] = i;
		}
	}
	return false;


}

    bool containsNearbyDuplicate(vector<int>& nums, int k) 
    {
    	bool flag = false;
	std::vector<int>::iterator it;
	for (it = nums.begin();it!=nums.end();it++)
	{
		int pos = find(nums.begin(), nums.end(), *it) - it;
		if(pos != 0 && abs(pos) <=k && abs(pos)<nums.size())
		{
			flag = true;
			break;
		}	
	}
	return flag;
    } // It's a right solution, time exceeds though.

int main()
{
	int a[] = {1,2,3,4,5,3,2,1};
	std::vector<int> v(a,a+sizeof(a)/sizeof(int));
	cout<<containsNearbyDuplicate(v,12)<<endl;
	return 0;
}