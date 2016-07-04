
/*

Leetcode: 220 Contains duplicate III
https://leetcode.com/problems/contains-duplicate-iii/

Given an array of integers, find out whether there are two distinct indices i and j in the array such that the difference between nums[i] and nums[j] is at most t and the difference between i and j is at most k.

*/

// trick 1: long is used to avoid substraction overflow 
// trick 2: difference between set and unordered_set
// http://stackoverflow.com/questions/1349734/why-on-earth-would-anyone-use-set-instead-of-unordered-set
// set: order matters; (std::less)
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
                    if(val - *higher <= t) {
                        return true;
                    }
                }
            }
            s.insert(val);
        }
        return false;
    }


    //solution 2: use sort from vector
        bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        
        vector<pair<int,int>> v;
        for(int i=0; i<nums.size(); i++) {
            v.push_back(make_pair(nums[i], i));
        }
        sort(v.begin(), v.end(), [](const pair<int,int> &p1, const pair<int,int> &p2)->bool {return p1.first< p2.first;});
        
        int start = 0, end = 0;
        while(start < nums.size()) {
            while(end+1 < nums.size() && (long)v[end+1].first - v[start].first <=t) {
                end++;
            }
            for(int i=start+1; i<=end; i++) {
                if(abs(v[start].second-v[i].second)<=k) {
                    return true;
                }
            }
            
            start++;
            end = start;
            
        }
    
    return false;
}



    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        
        vector<pair<long,int>> v;
        for(int i=0; i<nums.size(); i++) {
            v.push_back(make_pair(nums[i], i));
        }
        
        sort(v.begin(), v.end());
        
        for(int start = 0; start< nums.size(); start++) {
            int end =start+1;
            while(end<nums.size() &&v[end].first-v[start].first <= t) {
                if(abs(v[end].second - v[start].second) <= k) {
                    return true;
                }
                end++;
            }
        }
    
    return false;
}

