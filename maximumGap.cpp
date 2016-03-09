
/*
LintCode: maximum gap

LeetCode: maximum gap 
https://leetcode.com/problems/maximum-gap/
*/


// solution 2: radix sort
??

// solution 1: bucket sort

class Solution {
public:
      int maximumGap(vector<int> nums) {
       if(nums.size() < 2) {
           return 0;
       }
       
       int minNum = INT_MAX;
       int maxNum = INT_MIN;
       
       for(int i:nums) {
           minNum = min(i, minNum);
           maxNum = max(i, maxNum);
       }
       int len = nums.size();
       int inter = (maxNum - minNum)/len + 1;
       int bucket = (maxNum - minNum)/inter + 1;
       
       vector<int> localMax(bucket, INT_MIN);
       vector<int> localMin(bucket, INT_MAX);
       vector<int> used(bucket, 0);
       for(int i=0; i<nums.size(); i++) {
           int key = (nums[i]-minNum)/inter;
           
           localMax[key] = max(localMax[key], nums[i]);
           localMin[key] = min(localMin[key], nums[i]);
           // mark as visited
           used[key] = 1;
       }
       
       int gap = 0;
       int prev = 0;
       for(int i=1; i<bucket;i++) {
           if(used[i] == 0) {
               continue;
           }
           gap = max(gap, localMin[i]-localMax[prev]);
           prev = i;
       }
       return gap;
       
   }
}; 