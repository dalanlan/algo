

/*
LintCode: search in a rotated sorted array ii 
http://www.lintcode.com/zh-cn/problem/search-in-rotated-sorted-array-ii/

What if we have duplicates?

*/

class Solution {
    /** 
     * param A : an integer ratated sorted array and duplicates are allowed
     * param target :  an integer to be search
     * return : a boolean 
     */
public:
    bool search(vector<int> &A, int target) {
        int lo = 0, hi = A.size()-1, mid;

        while(lo <= hi) {
        	mid = (lo + hi)/2;
        	if(A[mid] == target) {
        		return true;
        	}

        	if(A[mid] < A[hi]) {
        		if(A[mid] < target && target <= A[hi]) {
        			lo = mid+1;
        		}
        		else {
        			hi = mid-1;
        		}
        		
        	}
        	else if(A[mid] > A[hi]) {
        		if(A[mid] > target && target > A[hi]) {
        			hi = mid-1;
        		}
        		else {
        			lo = mid+1;
        		}
        	}
        	else {
        		hi--;
        	}
        }
        return false;
    }
};