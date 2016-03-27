
/*
LeetCode: count of range sum
https://leetcode.com/problems/count-of-range-sum/
*/

// solution 1: native solution
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        // trivial O(n^2) solution 
        int sz = nums.size();
        if(sz == 0) {
            return 0;
        }
        
        vector<int> sum(sz+1, 0);
       
        for(int i=0; i<sz; i++) {
            sum[i+1] = sum[i] + nums[i];
        }
        
        int res = 0;
        for(int i=0; i<sz; i++) {
            for(int j=i+1; j<=sz; j++) {
                int diff = sum[j]-sum[i];
                if(diff >= lower && diff <= upper) {
                    res ++;
                }
            }
        }
        return res;
        
    }
};