
/*
LintCode: minimum size subarray sum
http://www.lintcode.com/zh-cn/problem/minimum-size-subarray-sum/
*/


// solution 1: two-pointers
// a little complicated and introduce dup
// O(n^2)
class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @param s: an integer
     * @return: an integer representing the minimum size of subarray
     */
    int minimumSize(vector<int> &nums, int s) {
        // write your code here
        int sz = nums.size();
        if(sz == 0) {
            return -1;
        }
        if(sz == 1) {
            return (nums[0]>=s?1:-1);
        }
        
        
        int sum;
        int count = INT_MAX;
        int slow = 0, fast;
        
        while(slow < sz) {
            fast = slow;
            sum = 0;
            while(fast < sz && sum < s) {
                sum += nums[fast];
                fast++;
            }
            if(sum >= s) {
                count = min(count, fast-slow);
            }
            slow++;
        }
        
        if(count != INT_MAX) return count;
        else return -1;
    }
};

// solution 2: sliding window
// O(n)
  int minimumSize(vector<int> &nums, int s) {
 	int count = INT_MAX;

 	int start = 0, end = 0;
 	int sum = 0;
 	while(end < nums.size()) {
 		sum+=nums[end++];
 		while(sum >= s) {
 			count = min(count, end-start);
 			sum -= nums[start++];	
 		}
 		
 	}
 	return count==INT_MAX?-1:count;
 }