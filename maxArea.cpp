
/*
Lintcode: container with most water
http://www.lintcode.com/zh-cn/problem/container-with-most-water/
*/

class Solution {
public:
    /**
     * @param heights: a vector of integers
     * @return: an integer
     */
    int maxArea(vector<int> &heights) {
        // write your code here
        int lo = 0, hi=heights.size()-1;
        int area = 0;
        while(lo < hi) {
            area = max(area, (hi-lo)*min(heights[hi], heights[lo]));
            if(heights[lo] < heights[hi]) {
                lo++;
            }
            else {
                hi--;
            }
            
        }
        return area;
    }
};