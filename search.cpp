// Search in Rotated Sorted Array

int search(vector<int>& nums, int target) {
int lo = 0, hi = nums.size()-1, mid;

while(hi - lo >= 0) {
	mid = lo + (hi - lo)/2;
	if (nums[mid] == target)
		return mid;
	
	if(nums[mid] > nums[hi]) {
		if(target < nums[mid] && target > nums[hi]) 
			hi = mid - 1;
		
		else
			lo = mid + 1;
	}
    
    // nums[mid] < nums[hi]
	else {
		if (target > nums[mid] && target <= nums[hi]) 
			lo = mid + 1;
		else 
			hi = mid - 1;
	}

}
return -1;
}