
/*

Leetcode: increasing triplet subsequence
https://leetcode.com/problems/increasing-triplet-subsequence/

*/

bool increasingTriplet(vector<int>& nums) {
    vector<int> tail;
    for(int i=0; i<nums.size(); i++) {
        auto iter = lower_bound(tail.begin(), tail.end(), nums[i]);
        if(iter == tail.end()) {
            tail.push_back(nums[i]);
        }
        else {
            *iter = nums[i];
        }
    }
    return tail.size() >= 3;
}

bool (vector<int>& nums) {
    int cand1 = INT_MAX;
    int cand2 = INT_MAX;
    for(int n:nums) {
        if(n <= cand1) {
            cand1 = n;
        }
        else if(n <= cand2) {
            cand2 = n;
        }
        else {
            return true;
        }
    }
    return false;
}