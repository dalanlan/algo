
/*

LintCode : Subarray sum 
http://www.lintcode.com/zh-cn/problem/subarray-sum/

Given an array of integers, find out the subarray 
with sum zero. Return the index of the first number
and the index of the last number
*/

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number 
     *          and the index of the last number
     */
    
    // This is a bad idea without any optimization
    vector<int> subarraySum(vector<int> nums){
        int lo = 0, hi;
        int sum = 0;
        vector<int> res;

        while(lo<nums.size()) {
        	sum += nums[lo];
        	hi = lo+1;
        	while(sum != 0 && hi < nums.size()) {
        		sum += nums[hi++];
        	}
        	if(sum == 0) {
        		res.push_back(lo);
        		res.push_back(hi-1);
        		return res;
        	}
            lo++;
            sum = 0;
        }
        return res;
    }
};

//O(n) solution

vector<int> subarraySum(vector<int> nums) {
	// <sum, index> pair
	unordered_map<int, int> map;

	// initialization
	map[0] = -1;
	int sum = 0;
	vector<int> res;
	for(int i=0; i<nums.size();i++) {
		sum += nums[i];
		if(map.find(sum) != map.end()) {
			res.push_back(map[sum]+1);
			res.push_back(i);
			return res;
		}
		map[sum] = i;

	}
	return res;
}