
/* 
LintCode : majority number
Given an array of integer, find out the majority number,
which occurs more then 1/2 times of the whole array.
*/

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: The majority number
     */
    int majorityNumber(vector<int> nums) {
        int sz = nums.size();
        if(sz == 0) {
        	return 0;
        }
        int cand = nums[0];
        int count = 1;

        for(int i=1;i<sz;i++) {
        	if(nums[i] != cand) {
        		count--;
        		if(count == 0) {
        			if(i+1<sz) {
        				cand = nums[i+1];
        				count=0;
        			}
        		}
        	}
        	else {
        		count++;
        	}
        	
        }
        return cand;
    }
};


    int majorityNumber(vector<int> nums) {
        int sz = nums.size();
        if(sz == 0) {
            return INT_MAX;
        }
        int cand = nums[0];
        int count = 1;
        for(int i=1;i<sz;i++) {
            if(cand == nums[i]) {
                count++;
            }
            else {
                count--;
            }
            if(count==0) {
                cand = nums[i];
                count=1;
            }
        }
        return cand;
    }
    