

/*
LintCode: next-permutation

http://www.lintcode.com/zh-cn/problem/next-permutation/
*/

class Solution {
public:
    /**
     * @param nums: An array of integers
     * @return: An array of integers that's next permuation
     */
    vector<int> nextPermutation(vector<int> &nums) {
        if(nums.size() <= 1) {
            return nums;
        }
        int l = nums.size()-2;
        while(l>=0 && nums[l] >= nums[l+1]) l--;
        if(l < 0) {
            reverse(nums.begin(), nums.end());
            return nums;
        }
        int k = nums.size()-1;
        while(k>=0 && nums[k] <= nums[l]) k--;
        swap(nums[l], nums[k]);
        reverse(nums.begin()+l+1, nums.end());
        return nums;
    }
};