
/*
LintCode: three sum 
http://www.lintcode.com/zh-cn/problem/3sum/
*/

class Solution {
public:    
    /**
     * @param numbers : Give an array numbers of n integer
     * @return : Find all unique triplets in the array which gives the sum of zero.
     */
    vector<vector<int> > threeSum(vector<int> &nums) {
        // write your code here
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<nums.size()-2; i++) {
            if(i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            
            twoSum(nums, i+1, nums[i], res);
        }
        return res;
    }
    void twoSum(vector<int> &nums, int index, int target, vector<vector<int>> &res) {
        int tar = -target;
        int sz = nums.size();
        int lo = index;
        int hi = sz-1;
        
        while(lo < hi) {
            int sum = nums[lo] + nums[hi];
            if(sum == tar) {
                res.push_back(vector<int>{target, nums[lo], nums[hi]});
                do{lo++;} while(lo < sz && nums[lo] == nums[lo-1]);
                do{hi--;} while(hi >= 0 && nums[hi] == nums[hi+1]);
            }
            else if(sum < tar) {
                lo++;
            }
            else {
                hi--;
            }
        }
    }
};
