
/*
leetCode: contains duplicate II
https://leetcode.com/problems/contains-duplicate-ii/

Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the difference between i and j is at most k.
*/

bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_set<int> s;
    for(int i=0; i<nums.size(); i++) {
        if(!s.empty()) {
            if(s.size() > k) {
                s.erase(nums[i-k-1]);
            }
            if(s.count(nums[i]) > 0) {
                return true;
            }
        }
        s.insert(nums[i]);
    }
    return false;
}