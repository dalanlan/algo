
/*
LeetCode: missing range

Given a sorted integer array where the range of elements are [lower, upper] inclusive, return its missing ranges.

For example, given [0, 1, 3, 50, 75], lower = 0 and upper = 99, return ["2", "4->49", "51->74", "76->99"].

*/

vector<string> missingRange(vector<int>& nums, int lower, int upper) {
	vector<string> res;

	int prev=lower-1, int cur;

	for(int i=0; i<=nums.size(); i++) {
		cur = i==nums.size()?upper+1:nums[i];
		if(cur - prev > 1) {
			res.push_back(getRange(prev+1, cur-1));
		}
		prev = cur;
	}
	return res;
}

string getRange(int lo, int hi) {
	return lo==hi?to_string(lo):to_string(lo)+"->"+to_string(hi);
}
