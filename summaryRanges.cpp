
/*
LeetCode: summary Ranges
https://leetcode.com/problems/summary-ranges/
*/


vector<string> summaryRanges(vector<int>& nums) {
    vector<string> res;
    int sz = nums.size();
    if(sz == 0) {
        return res;
    }
    
    
    int beginInd = 0, endInd = 0;
    
    while(endInd < sz) {
        while(endInd+1<sz && nums[endInd+1] == nums[endInd]+1) {
            endInd++;
        }
        else {
            if(beginInd == endInd) {
                res.push_back(to_string(nums[beginInd]));
            }
            else {
                res.push_back(to_string(nums[beginInd])+"->"+to_string(nums[endInd]));
            }
            beginInd = endInd+1;
            endInd = beginInd;
        }
    }
    return res;
}