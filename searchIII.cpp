
/*
LintCode : search in a rotated sorted array
http://www.lintcode.com/zh-cn/problem/search-in-rotated-sorted-array/
*/


class Solution {
    /** 
     * param A : an integer ratated sorted array
     * param target :  an integer to be searched
     * return : an integer
     */
public:
    int search(vector<int> &A, int target) {
        int lo = 0, hi = A.size()-1, mid;

        while(lo <= hi) {
        	mid = (lo+hi)/2;
        	if(A[mid] == target) {
        		return mid;
        	}
        
        	if(A[mid] < A[hi]) {
        		if(A[hi] >= target && target > A[mid]) {
        			lo = mid+1;
        		}
        		else {
        			hi = mid-1;
        		}
        	}

        	else {
        		if(target > A[hi] && target < A[mid]) {
        			hi = mid-1;
        		}
        		else {
        			lo = mid+1;
        		}

        	}
        }
        return -1;
    }
};