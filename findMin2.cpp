// Find Minimum in Rotated Sorted Array

int findMin(vector<int>& nums) {
	
	int lo = 0, hi = nums.size()-1;
	int mid;
	int minNum = nums[0];
	while(lo < hi) {
		mid = lo + (hi - lo)/2;

		if(nums[lo] < nums[mid]) {
			minNum = min(minNum, nums[lo]);
			lo = mid+1;
		}
		else if(nums[mid] < nums[hi]) {
			minNum = min(minNum, nums[mid]);
			hi = mid-1;
		}
		else 
			lo++;
		
	}
	minNum = min(minNum, nums[lo]);
	return minNum;
}

int findMin(vector<int>& nums){
	int lo = 0, hi = nums.size()-1, mid;
	while(lo < hi) {
		mid = lo + (hi - lo)/2;
		if(nums[mid] > nums[hi]) {
			lo = mid+1;
		}
		else {
			hi = mid;
		}
	}
	return nums[lo];
}