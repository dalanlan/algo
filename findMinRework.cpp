
/*
153. Find Minimum in Rotated Sorted Array
https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

You may assume no duplicate exists in the array.
*/


class Solution {
public:
    int findMin(vector<int>& nums) {
        int lo = 0, hi = nums.size()-1;
        while(lo < hi) {
            int mid = (lo+hi)/2;
            if(nums[mid] < nums[hi]) {
                hi = mid;
            }
            else {
                lo = mid+1;
            }
        }
        return nums[lo];
    }
};


/*
154. Find Minimum in Rotated Sorted Array II
https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/

What if duplicates are allowed?
*/


class Solution {
public:
    int findMin(vector<int>& nums) {
        int lo = 0, hi = nums.size()-1;
        
        while(lo < hi) {
            int mid = (lo+hi)/2;
            
            if(nums[mid] > nums[hi]) {
                lo = mid + 1;
            }
            else if(nums[mid] < nums[hi] ) {
                hi = mid;
            }
            else {
                hi--;
            }
        }
        return nums[lo];
    }
};