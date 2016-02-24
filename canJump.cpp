
/*
LintCode: jump game
http://www.lintcode.com/zh-cn/problem/jump-game/
*/

// solution 1: dynamic programming
// TLE
class Solution {
public:
    /**
     * @param A: A list of integers
     * @return: The boolean answer
     */
    bool canJump(vector<int> A) {
        // write you code here
        int sz = A.size();
        if(sz == 0) {
            return false;
        }
        
        vector<bool> v(A.size(), 0);
        v[0] = true;
        // dynamic programming
        for(int i=0; i<sz; i++) {
            // v[i]: indicate whether we can get ith position
        
            for(int j=0; j<A[i]; j++) {
                v[i+j] = v[i] || v[i+j];
                if(i+j == sz-1 && v[i+j] == true) {
                    return true;
                }
            }
        }
        return v[sz-1];
    }
};


// solution 2: dynamic programming
// TLE again
    bool canJump(vector<int> A) {
        int sz = A.size();
        if(sz == 0) {
            return false;
        }
        //int dp[sz]={false};
        vector<bool> dp(sz, false);
        dp[0] = true;
        
        for(int i=1; i<sz; i++) {
            for(int j=0; j<i; j++) {
                if(dp[j] && j+A[j] >= i) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[sz-1];
    }


    // solution 3: greedy
         bool canJump(vector<int> A) {
         int maxPos = 0;
         int sz = A.size();
         for(int i=0; i<sz; i++) {
             maxPos = max(maxPos, i+A[i]);
             if(maxPos <= i && i!= sz-1) {
                 return false;
             }
         }
         return true;
         
     }

     // solution 4: greedy 2
         bool canJump(vector<int> A) {
        if(A.size() == 0) {
            return false;
        }
        
        int maxPos = A[0];
        for(int i=1; i<A.size(); i++) {
            if(i<=maxPos && i+A[i] > maxPos) {
                maxPos = i+A[i];
            }
        }
        return maxPos>=A.size()-1;
    }

