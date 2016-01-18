
/*
LeetCode 215: Kth largest Element in an array

Find the kth largest element in an unsorted array. 
Note that it is the kth largest element in the sorted order, not the kth distinct element.

For example,
Given [3,2,1,5,6,4] and k = 2, return 5.

Note: 
You may assume k is always valid, 1 ≤ k ≤ array's length.

*/

// plain solution: not good, bad actually
int findKthLargest(vector<int>& nums, int k) {
	sort(nums.begin(), nums.end());
	return nums[nums.size()-k];
}


// quick select
int findKthLargest(vector<int>& nums, int k) {
	int sz = nums.size();
	if(sz == 0) {
		return INT_MAX;
	}
	// find kth smallest case, then we can save the 
	// change to the last param
	return findKthLargest(nums, 0, sz-1, sz-k);
}

int findKthLargest(vector<int>& nums, int start, int end, int k) {
	
	int pivot = nums[end];
	int left = start;
	for(int i=start; i < end; i++) {
		if(nums[i] <= pivot) {
			swap(nums[i], nums[left++]);
		}
	}
	swap(nums[end], nums[left]);
	if(left == k) {
		return nums[left];
	}
	else if (left < k) {
		return findKthLargest(nums, left+1, end, k);
	}
	else {
		return findKthLargest(nums, start, left-1, k);
	}
}