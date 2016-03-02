

/*
LintCode: kth largest element
http://www.lintcode.com/zh-cn/problem/kth-largest-element/
*/


// solution 1: TLE
// wrong algorithm to swap the element

class Solution {
public:
    /*
     * param k : description of k
     * param nums : description of array and index 0 ~ n-1
     * return: description of return
     */
     
    int kthLargestElement(int k, vector<int> nums, int lo, int hi) {
        if(lo > hi) {
            return INT_MAX;
        }
        // lo<=hi
        
        int pivot = nums[lo];
        int left=lo, right=hi;
        while(left < right) {
            while(left <= hi && nums[left] < pivot) {
                left++;
            }
            while(right >= lo && nums[right] > pivot) {
                right--;
            }
            if(left < right) {
                swap(nums[left], nums[right]);
            }
        }
        if(left == nums.size()-k) {
            return nums[left];
        }
        else if(left > nums.size()-k) {
            return kthLargestElement(k, nums, lo, left-1);
        }
        else {
            return kthLargestElement(k, nums, left+1, hi);
        }
        
    }
    int kthLargestElement(int k, vector<int> nums) {
        // write your code here
        if(nums.size() == 0) {
            return INT_MIN;
        }
        return kthLargestElement(k, nums, 0, nums.size()-1);
    }
};

// AC

class Solution {
public:
    /*
     * param k : description of k
     * param nums : description of array and index 0 ~ n-1
     * return: description of return
     */
     
    int kthLargestElement(int k, vector<int> nums, int lo, int hi) {
        if(lo > hi) {
            return INT_MAX;
        }
        // lo<=hi
        
        
        int pivot = nums[lo];
        int right = hi;
        for(int i=hi; i>lo; i--) {
            if(nums[i] >= pivot) {
                swap(nums[i], nums[right--]);
            }
        }
        swap(nums[right], nums[lo]);
        if(right == nums.size()-k) {
            return nums[right];
        }
        else if(right > nums.size()-k) {
            return kthLargestElement(k, nums, lo, right-1);
        }
        else {
            return kthLargestElement(k, nums, right+1, hi);
        }
        
    }
    int kthLargestElement(int k, vector<int> nums) {
        // write your code here
        if(nums.size() == 0) {
            return INT_MIN;
        }
        return kthLargestElement(k, nums, 0, nums.size()-1);
    }
};