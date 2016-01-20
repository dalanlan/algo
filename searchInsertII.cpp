
/*
LintCode 60: Search insertion position
*/

// binary search 

class Solution {
    /** 
     * param A : an integer sorted array
     * param target :  an integer to be inserted
     * return : an integer
     */
public:
    int searchInsert(vector<int> &A, int target) {
    	int lo=0, hi=A.size();
    	int mid;
    	while(lo<hi) {
    		mid = lo+((hi-lo)>>1);
    		if(A[mid]>=target) {
    			hi=mid;
    		}
    		else{
    			lo=mid+1;
    		}
    	}
    	return lo;
    }
}; 