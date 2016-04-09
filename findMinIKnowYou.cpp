
/*
Problem 1:
LintCode: find minimum in rotated array
http://www.lintcode.com/zh-cn/problem/find-minimum-in-rotated-sorted-array/


Suppose a sorted array is rotated at some pivot unknown to you beforehand.
(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
Find the minimum element.

You may assume no duplicate exists in the array.
Example
Given [4, 5, 6, 7, 0, 1, 2] return 0
*/

int findMin(vector<int> nums) {
	int lo = 0, hi = nums.size()-1;

	while(lo < hi) {
		int mid = (lo + hi)/2;
		if(nums[mid] > nums[hi]) {
			lo = mid+1;
		}
		else {
			hi = mid;
		}
	}
	return nums[lo];
}

/*
Lintcode: find min in rotated sorted array ii 
http://www.lintcode.com/en/problem/find-minimum-in-rotated-sorted-array-ii/

Suppose a sorted array is rotated at some pivot unknown to you beforehand.
(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
Find the minimum element.
The array may contain duplicates.
Given [4,4,5,6,7,0,1,2] return 0
*/


int findMin(vector<int> &nums) {
	int lo = 0, hi = nums.size()-1, mid;
	while(lo < hi) {
		mid = (lo+hi)/2;
		if(nums[mid]>nums[hi]) {
			lo = mid+1;
		}
		else if(nums[mid] < nums[hi]) {
			hi = mid;
		}
		else {
			hi--;
		}
	}
	return nums[lo];
}