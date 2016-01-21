
/*
LintCode :Find the missing number
给出一个包含 0 .. N 中 N 个数的序列，找出0 .. N 中没有出现在序列中的那个数。
*/

class Solution {
public:
    /**    
     * @param nums: a vector of integers
     * @return: an integer
     */
    int findMissing(vector<int> &nums) {
        int sum = 0;
        for(int i=0; i < nums.size(); i++) {
        	sum += i;
        	sum -=nums[i];
        }
        return sum+nums.size();
    }
};