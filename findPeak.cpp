

/*
LintCode :find peak
http://www.lintcode.com/zh-cn/problem/find-peak-element/

O(logn)
*/

class Solution {
public:
    /**
     * @param A: An integers array.
     * @return: return any of peek positions.
     */
    int findPeak(vector<int> A) {
    //     for(int i=1; i<A.size()-1; i++) {
    //         if(A[i] > A[i-1] && A[i] > A[i+1]) {
    //             return i;
    //         }
    //     }
    //     return -1;
    // }
    
    int lo = 0, hi = A.size()-1;
    
    while(lo <= hi) {
        int mid = (lo+hi)/2;
        if(A[mid] > A[mid-1] && A[mid] > A[mid+1]) {
            return mid;
        }
        else if(A[mid] > A[mid-1]) {
            lo = mid+1;
        }
        else {
            hi = mid-1;
        }
    }
        return lo;
    }
};
