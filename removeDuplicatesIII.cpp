
/*
LintCode 删除排序数组中的重复数字 II
如果可以允许出现两次重复将如何处理？
*/

class Solution {
public:
    /**
     * @param A: a list of integers
     * @return : return an integer
     */
    int removeDuplicates(vector<int> &nums) {
        int sz = nums.size();
        if(sz <= 2) {
        	return sz;
        }

        int count = 2;
        for(int i=2; i<sz; i++) {
        	if(nums[i] != nums[count-2]) {
        		nums[count++] = nums[i];
        	}
        }
        return count;
    }
};


int removeDuplicates(vector<int>& nums) {
        int i=0;
        for(int n:nums){
            if(i<2 || n > nums[i-2]) {
                nums[i++]=n;
            }
        }
        return i;
    }