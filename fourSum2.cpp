
/*
LintCode: four sum
http://www.lintcode.com/zh-cn/problem/4sum/
*/

class Solution {
public:
    /**
     * @param numbers: Give an array numbersbers of n integer
     * @param target: you need to find four elements that's sum of target
     * @return: Find all unique quadruplets in the array which gives the sum of 
     *          zero.
     */
    vector<vector<int> > fourSum(vector<int> nums, int target) {
        // write your code here
        vector<vector<int>> res;
        if(nums.size() < 4) {
            return res;
        }
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<nums.size()-3; i++) {
            if(i>0 && nums[i-1] == nums[i]) {
                continue;
            }
            threeSum(res, nums, target-nums[i], i+1, nums[i]);
        }
        return res;
    }
    
    void threeSum(vector<vector<int> > &res, vector<int> &nums, int target, int index, int cand1) {
        for(int i=index; i<nums.size()-2; i++) {
            if(i>index && nums[i-1] == nums[i]) {
                continue;
            }
            twoSum(res, nums, target-nums[i], i+1, cand1, nums[i]);
            
        }
    }
    void twoSum(vector<vector<int> > &res, vector<int> &nums, int target, int index, int cand1, int cand2) {
        int sz = nums.size();
        int lo = index, hi = sz-1;
        
        while(lo < hi) {
            int sum = nums[lo] + nums[hi];
            if(sum == target) {
                res.push_back(vector<int> {cand1, cand2, nums[lo], nums[hi]});
                do{lo++;}while(lo<sz && nums[lo] == nums[lo-1]);
                do{hi--;}while(hi>=0 && nums[hi] == nums[hi+1]);
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
