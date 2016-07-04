
    /*
    LeetCode: 
    https://leetcode.com/problems/top-k-frequent-elements/

    Given a non-empty array of integers, return the k most frequent elements.

    http://www.geeksforgeeks.org/find-the-k-most-frequent-words-from-a-file/
    */

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> counter;
        
        for(int i:nums) {
            counter[i]++;
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> que;
        
        for(auto x:counter) {
            que.push(make_pair(x.second, x.first));
            while(que.size() > k) {
                que.pop();
            }
        }
        
        
        vector<int> res;
        while(!que.empty()) {
            res.push_back(que.top().second);
            que.pop();
        }
        return res;
    
    }

