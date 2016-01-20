
/*
LeetCode 324: Wiggle sort II
Given an unsorted array nums, reorder it such that 
nums[0] < nums[1] > nums[2] < nums[3] ...

Follow-up: can you do it in O(n) time or/and in place
with O(1) extra space?

*/

// WA
// Special Judge: No expected output available.
void wiggleSort(vector<int>& nums) {
	int sz = nums.size();
    
    vector<int> rep(nums);
	sort(rep.begin(), rep.end());

	int even = 0, index = 0; 
	while(even < sz) {
		nums[even] = rep[index++];
		even += 2;
	}
	int odd = 1;
	while(odd < sz) {
		nums[odd] = rep[index++];
		odd += 2;
	}
	return;
}