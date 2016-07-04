/*
Leetcode: largest rectangle in histogram
https://leetcode.com/problems/largest-rectangle-in-histogram/
*/


class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int res = 0;
        // push 0 to help calculate the last histogram
        heights.push_back(0); 
        vector<int> bar;
        int i=0; 
        while(i<heights.size()) {
            if(bar.empty() || heights[i] > heights[bar.back()]) {
                bar.push_back(i++);
            }
            else {
                int bk = bar.back();
                bar.pop_back();
                res = max(res, heights[bk]*(bar.empty()?i:i-bar.back()-1));
            }
            
        }
        return res;
    }
};

int largestRectangleArea(vector<int>& heights) {
    int res = 0;
    heights.push_back(0);

    stack<int> s;
    int i=0;
    while(i<heights.size()) {
        if(s.empty() || heights[i] > heights[s.top()]) {
            s.push(i++);
        }
        else {
            int peak = s.top();
            s.pop();
            res = max(res, heights[peak] * (s.empty()?i:i-s.top()-1));
        }
    }
    return res;
