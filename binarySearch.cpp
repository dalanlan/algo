
/*
LintCode 14: Binary search

给定一个排序的整数数组（升序）和一个要查找的整数target，用O(logn)的时间查找到target第一次出现的下标（从0开始），如果target不存在于数组中，返回-1。

*/

class Solution {
public:
    /**
     * @param nums: The integer array.
     * @param target: Target number to find.
     * @return: The first position of target. Position starts from 0. 
     */
    int binarySearch(vector<int> &array, int target) {
        int lo=0, hi = array.size();
        int mid;
        while(lo < hi) {
        	mid = lo + ((hi-lo)>>1);
        	if(array[mid] >= target) {
        		hi=mid;
        	}
        	else {
        		lo = mid+1;
        	}
        }
        if(array[lo] == target) {
            return lo;
        }
        return -1;
    }
};