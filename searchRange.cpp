int binarySearch(vector<int>& nums,int target,int left,int right)
{
    if(right - left >1)
    {
    int mid = left + ((right - left) >> 1);
    if(nums[mid]==target)
        return mid;
    else if(nums[mid]<target)
        return binarySearch(nums,target,mid,right);
    else
        return binarySearch(nums,target,left,mid);
    }
    else
    {
        if(nums[left]==target)
            return left;
        else if (nums[right]==target)
            return right;
        else
            return -1;
    }
}
vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> res;
    
    int index=binarySearch(nums,target,0,nums.size()-1);
    
    if(index==-1)
    {
        res.push_back(-1);
        res.push_back(-1);
        return res;
    }
    
    int lower=index,upper=index;
    while(lower>0&&nums[lower-1]==target)
        lower--;
    while(upper<nums.size()-1 && nums[upper+1]==target)
        upper++;
    res.push_back(lower);
    res.push_back(upper);
    return res;
    
}