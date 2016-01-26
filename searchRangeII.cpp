
/*
LintCode: Search for a range
http://www.lintcode.com/zh-cn/problem/search-for-a-range/
*/

class Solution {
    /** 
     *@param A : an integer sorted array
     *@param target :  an integer to be inserted
     *return : a list of length 2, [index1, index2]
     */
public:
    vector<int> searchRange(vector<int> &A, int target) {
        int lo = 0, hi = A.size(), mid;
        int left,right;
        while(lo < hi) {
        	mid = (lo+hi)/2;
        	if(A[mid] >= target) {
        		hi = mid;
        	}
        	else {
        		lo = mid+1;
        	}
        }
        
        if(lo < A.size() && A[lo] == target) {
        	left = lo;
        }
        else {
        	// search failure
        	return vector<int>(2,-1);
        }

        lo = 0; 
        hi = A.size()-1;
        while(lo + 1< hi) {
        	mid = (lo+hi)/2;
        	if(A[mid] <= target) {
        		lo = mid;
        	}
        	else {
        		hi = mid;
        	}
        }
        if(A[hi] == target) {
            right = hi;
        }
        else {
            right = lo;
        }
        return vector<int>{left, right};

    }
};