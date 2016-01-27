
/*
LintCode: majority number ii
http://www.lintcode.com/zh-cn/problem/majority-number-ii/
*/

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: The majority number occurs more than 1/3.
     */
    int majorityNumber(vector<int> nums) {
       	if(nums.size() == 0) {
       		return INT_MAX;
       	}

       	int cand1, cand2, count1=0, count2=0;

       	for(int i=0; i<nums.size(); i++) {
       		if(count1 == 0) {
       			cand1 = nums[i];
       			count1 = 1;
       		}
       		else if(count2 == 0) {
       			cand2 = nums[i];
       			count2 = 1;
       		}
       		else if(cand1 == nums[i]) {
       			count1++;
       		}
       		else if(cand2 == nums[i]) {
       			count2++;
       		}
       		else {
       			count1--;
       			count2--;
       		}
       	}
       	if(count1 > 0) {
       		count1 = 0;
       		for(int i=0; i<nums.size(); i++) {
       			if(cand1 == nums[i]) {
       				count1++;
       			}
       		}
       		if(count1 > nums.size()/3) {
       			return cand1;
       		}
       	}
       	if(count2 > 0) {
       		count2 = 0;
       		for(int i=0; i<nums.size(); i++) {
       			if(cand2 == nums[i]) {
       				count2++;
       			}
       		}
       		if(count2 > nums.size()/3) {
       			return cand2;
       		}
       	}
       	return INT_MAX;


    }
};
