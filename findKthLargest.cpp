// Solution 1 : Quicksort
//
void quicksort(vector<int> &nums, int left, int right)
{
    if(nums.size()>1)
    {
    int i=left, j=right;
   
    int pivot= nums[(left+right)/2];
    
    while(i<=j)
    {
        while(nums[i]<pivot)
            i++;
        while(nums[j]>pivot)
            j--;
        if(i<=j)
        {
            swap(nums[i],nums[j]);
            i++;
            j--;
        }
        
    }
    //cout<<i<<" "<<j<<" "<<left<<" "<<right <<endl;
    
    if(left<j)
        quicksort(nums,left,j);
    if(i < right)
        quicksort(nums,i,right);
    }
}
int findKthLargest(vector<int>& nums, int k) {
    // quick sort and ... done!
    quicksort(nums,0,nums.size()-1);
    return nums[nums.size()-k];
}