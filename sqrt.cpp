
/*
LintCode: sqrt x
http://www.lintcode.com/zh-cn/problem/sqrtx/
*/

// solution 2
// use divide instead of multiply
    int sqrt(int x) {
        if(x <= 0) {
            return 0;
        }
        int lo = 1;
        int hi = x;
        
        while(lo <= hi) {
            int mid = (lo+hi)/2;
            if(mid<=x/mid) {
                if(mid+1 > x/(mid+1)) {
                    return mid;
                }
                lo = mid+1;
            }
            else {
                hi = mid-1;
            }
        }
    }

// The most significant problem is
// overflow
// solution 1: use `long` type to avoid it
class Solution {
public:
    /**
     * @param x: An integer
     * @return: The sqrt of x
     */
    int sqrt(int x) {
        // mock problem
        
        // binary search
        // the expected result which res*res<=x && (res+1)*(res+1)>x
        
        if(x <= 0) {
            // invalid
            return 0;
        }
        
        int lo = 1; 
        int hi = x;
        while(lo <= hi) {
            long mid = lo+(hi-lo)/2;
            if(mid*mid <= x && (mid+1)*(mid+1) > x) {
                return mid;
            }
            else if(mid*mid < x) {
                lo = mid+1;
            }
            else {
                hi = mid-1;
            }
        }
        return lo;
        
    }
};