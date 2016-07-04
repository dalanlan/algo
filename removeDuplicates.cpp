
//Remove Duplicates from Sorted Array

int removeDuplicates(vector<int> &nums)
{
	int length = 0;
	vector<int>::iterator it = nums.begin()
	while(it != nums.end() &&(it+1)!=nums.end() )
	{
		while(*it == *(it+1))
			nums.erase(it+1);
		length++;
		it++;
	}
	return length;
	
}

// one line solution
int removeDuplicates(vector<int>& nums) {
        return distance(nums.begin(),unique(nums.begin(),nums.end()));
    }



int removeDuplicates(vector<int>& nums) {
    int i = 0;
    for (int n : nums)
        if (!i || n > nums[i-1])
            nums[i++] = n;
    return i;
}

int removeDuplicates(vector<int>& nums) {
    int i = !nums.empty();
    for (int n : nums)
        if (n > nums[i-1])
            nums[i++] = n;
    return i;
}

int removeDuplicates(vector<int> &nums) {
    
        int sz = nums.size();
        if(sz == 0) {
            return 0;
        }
        int i = 0;
        for(int j=1; j<sz;j++) {
            if(nums[j] > nums[i]) {
                nums[++i] = nums[j];
            }
        }
        return i+1;
        
    }