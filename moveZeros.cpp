// Move zeros
// It's somewhat odd
void moveZeroes(vector<int>& nums) {
	int i=0, j=0;
	while(i<nums.size())
	{
		while(nums[i]!=0)
			i++;

		if(i<nums.size())
		{
		    j = i+1;
		    while(j<nums.size() && nums[j]==0)
			    j++;
		    if(j!=nums.size())
		    {
			    swap(nums[i],nums[j]);
			    i++;
		    }
		    else
			    return;
	    }
	    else return;
	}
}