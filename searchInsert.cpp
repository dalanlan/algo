
int binarySearch(vector<int>& nums, int target, int left, int right)
{
    if(right - left > 1)
    {
        int mid = left + ((right-left)>>1);
        if(nums[mid] == target)
            return mid;
        else if(nums[mid] > target)
            return binarySearch(nums,target,left,mid);
        else
            return binarySearch(nums,target,mid,right);
    }
    else if(target<nums[left])
        return left;
    else if(target==nums[left])
        return left;
    else if(target>nums[left] && target<=nums[right])
        return right;
    else if(target>nums[right])
        return (right+1);
}
int searchInsert(vector<int>& nums, int target) {
    return binarySearch(nums,target,0,nums.size()-1);
}