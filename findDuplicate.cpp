// Find the Duplicate Number 
// http://bookshadow.com/weblog/2015/09/28/leetcode-find-duplicate-number/

// Solution 1: Loop detection
int findDuplicate(vector<int>& nums) {
	int slow = 0;
	int fast = 0;

	while(true) {
		slow = nums[slow];
		fast = nums[nums[fast]];
		if(slow == fast)
			break;

	}
	int find = 0;
	while(true) {
		slow = nums[slow];
		find = nums[find];
		if(slow == find)
			return find;
	}


}

// Solution 2: Binary search + Pigeonhole principle

int findDuplicate(vector<int>& nums) {
	int lo = 1, hi = nums.size()-1, mid, count;

	while(lo <= hi) {
		mid = lo + (hi-lo) / 2;
		count = 0;
		for(int pos = 0; pos < nums.size(); pos++) {
			if (nums[pos] <= mid) {
				count++;
			}
		}
		if(count > mid)
			hi = mid - 1;
		else
			lo = mid + 1;

	}
	return lo;
}