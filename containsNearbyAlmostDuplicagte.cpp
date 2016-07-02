
/*
leetcode: contains duplicate iii
https://leetcode.com/problems/contains-duplicate-iii/

https://leetcode.com/discuss/45120/c-using-set-less-10-lines-with-simple-explanation
*/

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long> s;
        for(int i=0; i<nums.size(); i++) {
            long val = nums[i];
            if(!s.empty()) {
                if(s.size() > k) {
                    s.erase(nums[i-k-1]);
                }
                auto higher = s.lower_bound(val);
                if(higher!=s.end() && (*higher-val <=t) ) {
                    return true;
                }
                if(higher != s.begin()) {
                    higher--;
                    if(higher!=s.end() && (val - *higher <= t)) {
                        return true;
                    }
                }
            }
            s.insert(nums[i]);
        }
        return false;
    }
};


