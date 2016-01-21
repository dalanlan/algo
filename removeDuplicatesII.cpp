
/*
LintCode ???: Remove Duplicate numbers in the sorted array
*/

class Solution {
public:
    /**
     * @param A: a list of integers
     * @return : return an integer
     */
    int removeDuplicates(vector<int> &nums) {
    	int sz = nums.size();
    	if (sz == 0) {
    		return sz;
    	}

    	int count = 1;
    	for(int i=1;i<sz;i++) {
    		if(nums[i]!=nums[count-1])
    			nums[count++] = nums[i];
    	}
    	return count;

    }
};