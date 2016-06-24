

/*
LeetCode: top k frequent 
https://leetcode.com/problems/top-k-frequent-elements/
*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // sort the nums pair
        unordered_map<int,int> counter;
        for(int n:nums) {
            counter[n]++;
        }
        // pop out less frequent pairs
        // max-heap
        priority_queue<pair<int,int>> pq;
        for(auto c: counter) {
            pq.push(make_pair(c.second, c.first));
        }
        vector<int> res;
        while(res.size() < k) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};