
/*
LeetCode: Wiggle subsequence
https://leetcode.com/problems/wiggle-subsequence/
*/


// so-called 3-line solution
// 1. get rid of the consecutive elements
// 2. get rid of the consecutive increasing  elements

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int sz = nums.size();
        if(sz <= 1) {
            return sz;
        }
        
        bool increasing = nums[1] > nums[0];
        
        int prev = nums[0];
        int len = 1;
        
        for(int i=1; i<sz; i++) {
        
            if(increasing) {
                if(nums[i]>prev) {
                    len++;
                    increasing = !increasing;
                }
            }
            else {
                if(nums[i] < prev) {
                    len++;
                    increasing = !increasing;
                }
            }
            
            prev = nums[i];
        }
        return len;
            
    }
};