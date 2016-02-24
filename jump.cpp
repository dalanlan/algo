
/*
LintCode: jump game ii

*/

// solution 1: dynamic programming
// TLE
class Solution {
public:
    /**
     * @param A: A list of lists of integers
     * @return: An integer
     */
    int jump(vector<int> A) {
        // wirte your code here
        
        // greedy
        int sz = A.size();
        vector<int> dp(sz, INT_MAX);
        dp[0] = 0;
        for(int i=1; i<sz; i++) {
            for(int j=0; j<i; j++) {
                if(j + A[j]>=i) {
                    dp[i] = min(dp[i], dp[j]+1);
                }
            }
        }
        return dp[sz-1];
        
    }
};

// solution 2: greedy
// from right to left 

    int jump(vector<int> A) {
        
        int sz = A.size();
        if(sz == 0) {
            return -1;
        }
        int start=0, end=0, jumps=0, furthest;
        
        while(end < sz-1) {
            jumps++;
            furthest=end;
            for(int i=start; i<=end; i++) {
                if(A[i] + i > furthest) {
                    furthest = A[i] + i;
                }
            }
            start = end+1;
            end = furthest;
        }
        return jumps;
    }