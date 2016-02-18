
/*
LintCode: two sum
http://www.lintcode.com/zh-cn/problem/two-sum/
*/

class Solution {
public:
    /*
     * @param numbers : An array of Integer
     * @param target : target = numbers[index1] + numbers[index2]
     * @return : [index1+1, index2+1] (index1 < index2)
     */

    vector<int> twoSum(vector<int> &nums, int target) {
        // write your code here
        
        unordered_map<int, int> myMap;
        for(int i=0; i<nums.size(); i++) {
            myMap[nums[i]] = i;
        }
        vector<int> res;
        
        for(int i=0; i<nums.size(); i++) {
            if(myMap.find(target - nums[i]) != myMap.end()) {
                res.push_back(min(i, myMap[target-nums[i]])+1);
                res.push_back(max(i, myMap[target-nums[i]])+1);
                return res;
            }
        }
    }
};


    vector<int> twoSum(vector<int> &nums, int target) {
	 unordered_map<int, int> myMap;
	for(int i=0; i<nums.size(); i++) {
		if(myMap.find(nums[i]) != myMap.end()) {
			vector<int> res;
			res.push_back(myMap[nums[i]]+1);
			res.push_back(i+1);
			return res;
		}
		myMap[target-nums[i]] = i;
	}
	return vector<int> {-1, -1};
}