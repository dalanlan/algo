int findMin(vector<int>& nums){
	int lo = 0, hi = nums.size()-1, mid;
	while(lo < hi) {
		mid = lo + (hi - lo)/2;
		if(nums[mid] > nums[hi]) {
			lo = mid+1;
		}
		else if(nums[mid] < nums[hi]) {
			hi = mid;
		}
		else if(nums[lo] > nums[mid]) {
			hi = mid;
		}
		else if(nums[lo] < nums[mid]) {
			break;
		}
		else {
			lo++;
		}
	}
	return nums[lo];
}