
/*
LintCode: wood cut
http://www.lintcode.com/zh-cn/problem/wood-cut/
*/
class Solution {
public:
    /** 
     *@param L: Given n pieces of wood with length L[i]
     *@param k: An integer
     *return: The maximum length of the small pieces.
     */
    int woodCut(vector<int> L, int k) {
        // write your code here
        if(L.size() == 0) {
            return 0;
        }
        int lo=1, hi=0, mid;
        for(int i=0; i<L.size(); i++) {
            hi=max(hi, L[i]);
        }
        
       int tmp;
        while(hi > lo + 1) {
            mid = lo + (hi-lo)/2;
            tmp = countWood(L, mid);
            
            if(tmp >= k) {
                lo = mid;
            }
            else {
                hi = mid;
            }
        }
        if(countWood(L, hi) >= k) {
            return hi;
        }
        if(countWood(L, lo) >= k) {
            return lo;
        }
        return 0;
        
    }
    int countWood(vector<int> L, int len) {
        int count = 0;
        for(int i=0; i<L.size(); i++) {
            count += L[i]/len;
        }
        return count;
    }
};