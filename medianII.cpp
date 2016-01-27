
/*
LintCode: data stream median
http://www.lintcode.com/zh-cn/problem/data-stream-median/
*/

/*
priority_queue :default max-heap
priority_queue<int> q; (default)
priority_queue<int, vector<int>, greater<int>> q2; (min-heap)
*/

class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: The median of numbers
     */
    vector<int> medianII(vector<int> &nums) {
    	if(nums.size() <= 1) {
    		return nums;
    	}

    	// initialization
    	vector<int> res(2, min(nums[0],nums[1]));

    	//max-heap: to store smaller numbers
    	priority_queue<int> maxHeap;
    	//min-heap: to store larger numbers
    	priority_queue<int, vector<int>, greater<int>> minHeap;

    	maxHeap.push(min(nums[0], nums[1]));
    	minHeap.push(max(nums[0], nums[1]));

    	int maxTop, minTop, cur;
    	for(int i=2; i<nums.size(); i++) {
    		cur = nums[i];
    		maxTop = maxHeap.top();
    		minTop = minHeap.top();


    		if(cur < maxTop) {
    			if(maxHeap.size() <= minHeap.size()) {
    				maxHeap.push(cur);
    			}
    			else {
    				minHeap.push(maxTop);
    				maxHeap.pop();
    				maxHeap.push(cur);
    			}
    		}
    		else if(cur >= maxTop && cur <= minTop) {
    			if(maxHeap.size() <= minHeap.size()) {
    				maxHeap.push(cur);
    			}
    			else {
    				minHeap.push(cur);
    			}
    		}
    		else {
    			if(minHeap.size() <= maxHeap.size()) {
    				minHeap.push(cur);
    			}
    			else {
    				maxHeap.push(minTop);
    				minHeap.pop();
    				minHeap.push(cur);
    			}
    		}

    		if(minHeap.size() == maxHeap.size()) {
    			res.push_back((minHeap.top()+maxHeap.top())/2);
    		}
    		else if(minHeap.size() < maxHeap.size()) {
    			res.push_back(maxHeap.top());
    		}
    		else {
    			res.push_back(minHeap.top());
    		}


    	}

    	return res;

    }
};
