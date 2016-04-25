
/*
2016/04/24
Leetcode: find peak element
https://leetcode.com/problems/find-peak-element/
*/

// iterative
// the old one with LintCode is WA
// the basic idea is right though
// watch out the corner cases
    int findPeakElement(vector<int>& nums) {
        int lo = 0, hi = nums.size()-1;
        while(lo < hi) {
            int mid1 = (lo+hi)/2;
            int mid2 = mid1+1;
            if(nums[mid1] > nums[mid2]) {
                hi = mid1;
            }
            else {
                lo = mid2;
            }
        }
        return lo;
    }

     // recursive
    // pretty straight forward
    int findPeakElement(vector<int>& nums) {
        return findHelper(nums, 0, nums.size()-1);
    }
    int findHelper(vector<int>& nums, int lo, int hi) {
        if(lo == hi) {
            return lo;
        }
        int mid1 = (lo+hi)/2;
        int mid2 = (lo+hi)/2+1;
        if(nums[mid1] > nums[mid2]) {
            return findHelper(nums, lo, mid1);
        }
        else {
            return findHelper(nums,mid2, hi);
        }
    }