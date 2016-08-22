
/*
LeetCode: largest rectangle in histogram 
https://leetcode.com/problems/largest-rectangle-in-histogram/

Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.

*/


// store the index into the vector
int largestRectangleArea(vector<int>& heights) {
	
	vector<int> index;
	heights.push_back(0);
	int res = 0;
	int i=0;
	while(i<heights.size()) {
		if(index.empty() || heights[i] > heights[index.back()]) {
			index.push_back(i++);
		}
		else {
			int heig = index.back();
			index.pop_back();
			res = max(res, heights[heig] * (index.empty()?i:i-index.back()-1));	
		}
	}
	return res;
}