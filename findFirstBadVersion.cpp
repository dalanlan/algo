
/*
LintCode : The first bad version
http://www.lintcode.com/zh-cn/problem/first-bad-version/
*/

/**
 * class SVNRepo {
 *     public:
 *     static bool isBadVersion(int k);
 * }
 * you can use SVNRepo::isBadVersion(k) to judge whether 
 * the kth code version is bad or not.
*/
class Solution {
public:
    /**
     * @param n: An integers.
     * @return: An integer which is the first bad version.
     */
    int findFirstBadVersion(int n) {
        int lo=1, hi = n;
        while(lo < hi-1) {
        	int mid = lo + ((hi-lo)>>1);

        	if(isBadVersion(mid)) {
        		hi = mid;
        	}
        	else {
        		lo = mid+1;
        	}
        }
        if(isBadVersion(lo)) {
        
            return lo;
        }
        return hi;
    }
};
