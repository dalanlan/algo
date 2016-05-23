/*
Leetcode: maximal rectangle
https://leetcode.com/problems/maximal-rectangle/

Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all ones and return its area.

*/

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        
        if(matrix.size() == 0 || matrix[0].size() == 0) {
            return 0;
        }
        int row = matrix.size();
        int col = matrix[0].size();
        
        vector<vector<int>> hist = vector<vector<int>>(row, vector<int>(col, 0));
        
        // construct histogram
        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                if(matrix[i][j] == '0') {
                    hist[i][j] = 0;
                }
                else {
                    hist[i][j] = i==0?1:hist[i-1][j]+1;
                }
            }
        }
        int res = 0;
        // query the answer
        for(int i=0; i<row; i++) {
            res = max(res, largestHist(hist[i]));
        }
        return res;
    }
    int largestHist(vector<int>& nums) {
        stack<int> s;
        nums.push_back(0);
        int res = 0;
        int i = 0;
        while(i<nums.size()) {
            if(s.empty() || nums[i] > nums[s.top()]) {
                s.push(i++);
            }
            else {
                int peak = s.top();
                s.pop();
                res = max(res, nums[peak]*(s.empty()?i:i-s.top()-1));
            }
        }
        return res;
    }
};