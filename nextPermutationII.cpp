
/*
LintCode : next permutation II
http://www.lintcode.com/zh-cn/problem/next-permutation-ii/

*/

class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: return nothing (void), do not return anything, modify nums in-place instead
     */
    void nextPermutation(vector<int> &nums) {
        int sz = nums.size();
        if(sz <= 1) {
        	return;
        } 
        int k=sz-2;
        while(k >= 0 && nums[k] >= nums[k+1]) k--;

        if(k == -1) {
        	reverse(nums.begin(), nums.end());
        	return;
        }
        int l=sz-1;
        while(l >=0 && nums[l] <= nums[k]) l--;
        swap(nums[k], nums[l]);
        reverse(nums.begin()+k+1, nums.end());
        return ;
    }
};