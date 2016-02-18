
/*
LintCode: partition array
http://www.lintcode.com/zh-cn/problem/partition-array/
*/

class Solution {
public:
    int partitionArray(vector<int> &nums, int k) {
        // write your code here
        
        int lo = 0, hi = nums.size()-1;
        
        while(lo <= hi) {
            while(lo <= hi && nums[lo] < k) {
                lo++;
            }
            while(lo <= hi && nums[hi] >= k) {
                hi--;
            }
            if(lo <= hi) {
                swap(nums[lo], nums[hi]);
            }
        }
        return lo;
    }
};