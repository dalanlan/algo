
/*
LeetCode: Self Crossing
https://leetcode.com/problems/self-crossing/
*/

// https://discuss.leetcode.com/topic/38014/java-oms-with-explanation/2

// categorize the self-crossing problem into 3 scenarios
// 1. fourth line crosses the first line
// 2. fifth line crosses the first line
// 3. sixth line crosses the first line

bool isSelfCrossing(vector<int>& x) {
	int sz = x.size();
	if(sz <= 3) {
		return false;
	}		
	for(int i=3; i<sz; i++) {
		// case 1
		if(x[i] >= x[i-2] && x[i-1] <= x[i-3]) {
			return true;
		}
		// case 2
		if(i >= 4) {
			if(x[i-1] == x[i-3] && x[i] + x[i-4] >= x[i-2]) {
				return true;
			}
		}
		// case 3
		if(i >= 5) {
			if(x[i-3] <= x[i-1] + x[i-5] && x[i] + x[i-4] >= x[i-2] && x[i-2] >= x[i-4] && x[i-1] <= x[i-3]) {
				return true;
			}
		}
	}
	return false;
}