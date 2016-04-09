
/*
Leetcode: container with most water
https://leetcode.com/problems/container-with-most-water/
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int sz = height.size();
        int lo = 0, hi = sz-1;
        int area = 0;
        while(lo < hi) {
            int h=min(height[lo], height[hi]);
            area = max(area, h*(hi-lo));
            while(lo<hi && height[lo]<=h) {
                lo++;
            }
            while(lo<hi && height[hi]<=h) {
                hi--;
            }
        }
        return area;
    }
};