// Search in Rotated Sorted Array II
    bool search(vector<int>& nums, int target) {
	int lo = 0, hi = nums.size()-1, mid;

	while(hi - lo >= 0) {
		mid = lo + (hi - lo)/2;

		if(nums[mid] == target)
			return true;

		if(nums[mid] < nums[hi] ) {
			if(target > nums[mid] && target <= nums[hi])
				lo = mid + 1;
			else 
				hi = mid - 1;
		}
		else if (nums[mid] > nums[hi] ) {
			if(target >= nums[lo] && target < nums[mid])
				hi = mid - 1;
			else	
				lo = mid + 1;
		}
		else
			hi --;
 
	}
	return false;

}