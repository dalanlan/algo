
/*
LintCode 80: median number
return the median number of a unsorted array
*/


class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: An integer denotes the middle number of the array.
     */
    int median(vector<int> &nums) {
    	int sz = nums.size();
    	if(sz == 0) {
    		return INT_MAX;
    	}
    	int mid = (sz&1)?(sz/2):(sz/2-1);
    	return median(nums, 0, sz-1, mid);
    }


    int median(vector<int> &nums, int start, int end, int mid) {

        int pivot = nums[end];
        int left = start;
        for(int i=start; i<end; i++) {
        	if(nums[i] <= pivot) {
        		swap(nums[i],nums[left++]);
        	}
        }
        swap(nums[end], nums[left]);
        if(left == mid) {
        	return nums[left];
        }
        if(left < mid) {
        	return median(nums, left+1, end, mid);
        }
        else {
        	return median(nums, start, left-1, mid);
        }
    }
};
