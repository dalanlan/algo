
/*
Lintcode: previous permutation
http://www.lintcode.com/zh-cn/problem/previous-permutation/
*/

class Solution {
public:
    /**
     * @param nums: An array of integers
     * @return: An array of integers that's previous permuation
     */
    vector<int> previousPermuation(vector<int> &nums) {
        // write your code here
        int k=nums.size()-2;
        while(k >=0 && nums[k] <= nums[k+1]) {
            k--;
        }
        if(k == -1) {
            reverse(nums.begin(), nums.end());
            return nums;
        } 
        int i;
        for(i=k+1; i<nums.size()-1; i++) {
            if(nums[i] < nums[k] && nums[k] <= nums[i+1]) {
                break;
            }
        }
        
        swap(nums[i],nums[k]);
        reverse(nums.begin()+k+1, nums.end());
        return nums;
        
    }
};

vector<int> previousPermuation(vector<int> &nums) {
        int k=nums.size()-2;
        for(; k>=0; k--) {
            if(nums[k] > nums[k+1]) {
                break;
            }
        }
        if(k == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        int j = k+1;
        for(; j < nums.size()-1; j++) {
            if(nums[j] < nums[k] && nums[k] <= nums[j+1]) {
                break;
            }
        }
        swap(nums[j], nums[k]);
        reverse(nums.begin()+k+1, nums.end());
        return nums;
}