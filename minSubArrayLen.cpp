
/*
LeetCode: minimum size subarray sum
https://leetcode.com/problems/minimum-size-subarray-sum/
*/

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        
        int minLen = INT_MAX;
        if(nums.size() == 0) {
            return 0;
        }
        
        int start = 0, end = 0;
        int sum = 0;
        while(end < nums.size()) {
            sum += nums[end++];
            while(sum >= s) {
                if(end - start < minLen) {
                    minLen = end-start;
                }
                sum -= nums[start];
                start++;
            }
        }
        return minLen == INT_MAX?0:minLen;
    }
};