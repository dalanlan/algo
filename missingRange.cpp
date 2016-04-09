
/*
LeetCode: missing ranges
The online judge system  has been blocked
*/

vector<string> missingRanges(vector<int> nums) {
	vector<string> res;
	int startInd = 0;
	int start, end;
	int sz = nums.size();
	while(startInd < sz) {
		while(startInd+1 < sz && nums[startInd+1]=nums[startInd]+1) {
			startInd++;
		}
		if(startInd+1 < sz) {
			start = nums[startInd]+1;
			end = nums[startInd+1]-1;
			
			if(start == end) {
				res.push_back(to_string(start));
			}
			else {
				res.push_back(to_string(start) + "->" + to_string(end));
			}
			
		}
		startInd++;

	}
	return res;
}