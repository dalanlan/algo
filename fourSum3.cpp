
/*
LeetCode: four sum
https://leetcode.com/problems/4sum/
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        if(nums.size() < 4) {
            return res;
        }
        
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<nums.size()-3; i++) {
            if(i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            
            threeSum(nums, target-nums[i], nums[i], i+1, res);
        }
        return res;
        
    }
    void threeSum(vector<int>& nums, int target, int ele1, int index, vector<vector<int>> &res) {
        for(int i=index; i<nums.size()-2; i++) {
            if(i > index && nums[i] == nums[i-1]) {
                continue;
            }
            
            twoSum(nums, target-nums[i], ele1, nums[i], i+1, res);
        }
    }
    
    void twoSum(vector<int>& nums, int target, int ele1, int ele2, int index, vector<vector<int>> &res) {
        int lo = index, hi = nums.size()-1;
        while(lo < hi) {
            int sum = nums[lo] + nums[hi];
            if(sum == target) {
                res.push_back({ele1, ele2, nums[lo], nums[hi]});
                do {lo++;} while(lo < hi && nums[lo] == nums[lo-1]);
                do {hi--;} while(lo < hi && nums[hi] == nums[hi+1]);
            }
            else if(sum < target) {
                lo++;
            }
            else {
                hi--;
            }
        }
    }
};