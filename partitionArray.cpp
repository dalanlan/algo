
/* 
LintCode 373
Split an integer array, with odd numbers 
stand in front of the even numbers
*/

void partitionArray(vector<int> &nums) {
	int sz = nums.size();
	if(sz <= 1) {
		return;
	}
	int lo=0, hi=sz-1;
	while(lo <= hi) {
		while(lo < sz && (nums[lo] & 1)) {
			lo++;
		} 
		while(hi >= 0 && !(nums[hi] & 1)) {
			hi--;
		}
		if(lo <= hi) {
			swap(nums[lo], nums[hi]);		
		}
	}
	return ;
}