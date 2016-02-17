
/*
Lintcode: trapping rain water
http://www.lintcode.com/zh-cn/problem/trapping-rain-water/
*/

class Solution {
public:
    /**
     * @param heights: a vector of integers
     * @return: a integer
     */
    int trapRainWater(vector<int> &heights) {
        // write your code here
        
        if(heights.size() == 0) {
            return 0;
        }
        
        int lo = 0, hi = heights.size()-1;
        int left = heights[lo], right = heights[hi];
        int res = 0;
        
        while(lo < hi) {
            if(left <= right) {
                lo++;
            
                if(heights[lo] <= left) {
                    res += left - heights[lo];
                }
                else {
                    left = heights[lo];
                }
            }
            else {
                hi--;
                if(heights[hi] < right) {
                    res += right - heights[hi];
                }
                else {
                    right = heights[hi];
                }
            }
        }
        return res;
        
        
    }
};