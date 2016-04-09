
/*
Lintcode: majority number III
http://www.lintcode.com/zh-cn/problem/majority-number-iii/
*/


/*
LintCode: 
http://www.lintcode.com/zh-cn/problem/majority-number-iii/

*/
//  O(k) space complexity
int majorityNumber(vector<int> nums, int k) {
	unordered_map<int,int> map;
	for(int i=0;i<nums.size(); i++) {
		map[nums[i]]++;
	}
	int count = 0;
	int candidate=0;
	for(auto m:map) {
		if(m->second > count) {
			count = m->second;
			candidate = m->first;
		}
	}
	return candidate;
}