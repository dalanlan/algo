// Find minimum in rotated sorted array
int findMin(vector<int>& nums) {

int lo = 0, hi = nums.size()-1;
int minNum = nums[0];

while(hi - lo > 1) {
	int mid = lo + (hi - lo)/2;
	if(nums[lo] < nums[mid]) {
		minNum = min(nums[lo],minNum);
		lo = mid+1;
		
	}
	else if(nums[mid] < nums[hi]) {
		minNum = min(minNum, nums[mid]);
		hi = mid-1;
		
	}
	else
		lo++;
}

minNum = min(minNum,nums[lo]);
minNum = min(minNum,nums[hi]);

return minNum;
}