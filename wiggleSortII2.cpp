
/*
LintCode: wiggle sort ii
http://www.lintcode.com/zh-cn/problem/wiggle-sort-ii/
*/

// solution 1: sort()
class Solution {
public:
    /**
     * @param nums a list of integer
     * @return void
     */  
    void wiggleSort(vector<int>& nums) {
        // Write your code here
        vector<int> dup(nums);
        sort(dup.begin(), dup.end(), greater<int>());
        
        int sz = nums.size(), m = sz|1;
        for(int i=0; i<sz; i++) {
            nums[(2*i+1)%m] = dup[i];
        }
        
    }
};

// solution 2: 
// https://leetcode.com/discuss/76965/3-lines-python-with-explanation-proof
// https://leetcode.com/discuss/77022/short-simple-c

void wiggleSort(vector<int>& nums) {
	vector<int> sorted(nums);
	sort(sorted.begin(), sorted.end());

	for(int i=nums.size()-1, j=0, k=i/2+1;i>=0; i--) {
		nums[i] = sorted[i&1?k++:j++];
	}
}