

/*
LeetCode: sliding window maximum
https://leetcode.com/problems/sliding-window-maximum/
*/

// basic idea
// TLE
vector<int> maxSlidingWindow(vector<int> &nums, int k) {
	vector<int> res;
	 if(nums.size() == 0 || k == 0) {
        return res;
    }
	int start = 0, end =start+k;

	while(end <= nums.size()) {
		priority_queue<int> pq(nums.begin()+start, nums.begin()+end);
		res.push_back(pq.top());
		start++;
		end = start+k;
	}
	return res;

}


// solution 2: use a deque to store promising elements index
// pop_front() : those indexes out of range
// pop_back(): those indexes that are not likely to be max
// push_back(current index)
// deque.front(): current max

vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    vector<int> res;
    if(nums.size() == 0 || k <= 0) {
        return res;
    }
    
    deque<int> q;
    
    for(int i=0; i<nums.size(); i++) {
        
        // remove from head where it's out of range
        while(!q.empty() && q.front() < i-(k-1)) {
            q.pop_front();
        }
        
        // remove those numbers that are not promising
        while(!q.empty() && nums[q.back()] < nums[i]) {
            q.pop_back();
        }
        
        q.push_back(i);
        if(i >= k-1) {
            res.push_back(nums[q.front()]);
        }
    }
    return res;
}