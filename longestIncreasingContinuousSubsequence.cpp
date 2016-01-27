
/*
LintCode: longest increasing continuous subsequence
http://www.lintcode.com/zh-cn/problem/longest-increasing-continuous-subsequence/
*/


class Solution {
public:
    /**
     * @param A an array of Integer
     * @return  an integer
     */
    int longestIncreasingContinuousSubsequence(vector<int>& A) {
        int sz = A.size();
        if(sz <= 1) {
            return sz;
        }
        vector<int> res(sz, 1);
        
        int ans = 1;
        for(int i=1; i<sz; i++) {
            if(A[i] > A[i-1]) {
                res[i] = max(res[i], res[i-1]+1);
                ans = max(ans, res[i]);
            }
        }
        
        for(int i=0; i<sz; i++) {
            res[i] = 1;
        }
        for(int i=1; i<sz; i++) {
            if(A[i] < A[i-1]) {
                res[i] = max(res[i], res[i-1]+1);
                ans = max(ans, res[i]);
            }
        }
        return ans;
        
    
    }
};


// solution 2: O(1) space 
int longestIncreasingContinuousSubsequence(vector<int>& A) {
        int sz = A.size();
        if(sz <= 1) {
            return sz;
        }
        int ans = 1;
        int count = 1;
        
        for(int i=1; i<sz; i++) {
            if(A[i] > A[i-1]) {
                count++;
            }
            else {
                count = 1;
            }
            ans = max(ans, count);
        }
        count=1;
        for(int i=1; i<sz; i++) {
            if(A[i] < A[i-1]) {
                count++;
            }
            else {
                count = 1;
            }
            ans = max(ans, count);
        }
        return ans;
    }