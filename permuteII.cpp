/*
LintCode: permutations
http://www.lintcode.com/zh-cn/problem/permutations/
*/

class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: A list of permutations.
     */
    void permute(vector<vector<int>> &res, vector<int> &nums, int index) {
        if(index == nums.size()) {
            res.push_back(nums);
        }
        else {
            for(int i=index; i<nums.size(); i++) {
                swap(nums[i], nums[index]);
                permute(res, nums, index+1);
                swap(nums[i], nums[index]);
            }
        }
    }
    vector<vector<int> > permute(vector<int> nums) {
        vector<vector<int>> res;
        if(nums.size() == 0) {
            return res;
        }
        permute(res, nums, 0);
        return res;
    }
};
