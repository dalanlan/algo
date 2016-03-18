
/*
LeetCode: house robber ii
https://leetcode.com/problems/house-robber-ii/
*/

// a very brilliant idea:
// https://leetcode.com/discuss/36544/simple-ac-solution-in-java-in-o-n-with-explanation

class Solution {
public:
    
    int rob(vector<int>& nums, int lo, int hi) {
        int exclude = 0, include = 0;
        for(int k=lo; k<=hi; k++) {
            int e=exclude, i=include;
            include = e+nums[k];
            exclude = max(e, i);
        }
        return max(include, exclude);
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 0) {
            return 0;
        }
        if(nums.size() == 1) {
            return nums[0];
        }
        return max(rob(nums,0,nums.size()-2), rob(nums,1,nums.size()-1));
    }
};