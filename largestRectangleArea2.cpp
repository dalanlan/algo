
/*
LintCode: largest rectangle in histogram
http://www.lintcode.com/zh-cn/problem/largest-rectangle-in-histogram/
*/

class Solution {
public:
    /**
     * @param height: A list of integer
     * @return: The area of largest rectangle in the histogram
     */
    int largestRectangleArea(vector<int> &height) {
        // write your code here
        
        if(height.size() == 0) {
            return 0;
        }
        
        int res = 0;
        
        stack<int> bar;
        height.push_back(0);
        
        int i=0;
        // remember we put index into the stack
        while(i<height.size()) {
            if(bar.empty() || height[i] > height[bar.top()]) {
                bar.push(i++);
            }
            else {
                int bk = bar.top();
                bar.pop();
                res = max(res,height[bk]*(bar.empty()?i:(i-bar.top()-1)));
            }
        }
        return res;
        
    }
};
