
/*
LintCode: back pack
http://www.lintcode.com/zh-cn/problem/backpack/
*/


// solution 1: 2D vector
// dp[i][j] : whether first ith is able to get total j.

class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPack(int m, vector<int> A) {
        // write your code here
        
        // dp[i][S] = dp[i-1][S] || dp[i-1][S-A[i]
        int sz = A.size();
        if(sz == 0) {
            return 0;
        }
        vector<vector<bool> > dp = vector<vector<bool> >(sz+1, vector<bool> (m+1,false));
        
        for(int i=0; i<=sz; i++) {
            dp[i][0] = true;
        }
        
        for(int i=1; i<=sz; i++) {
            for(int j=1; j <= m; j++) {
                if(j >= A[i-1]) {
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-A[i-1]];
                }
                else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        for(int i=m; i>0; i--) {
            if(dp[sz][i]) {
                    return i;
            }
        }
        return 0;
    }
};

// solution 2: using 1D vector
int backPack(int m, vector<int> A) {
    int sz = A.size();
    vector<bool> dp(m+1, false);

    dp[0] = true;
    
    for(int i=0; i<sz;i++) {
        for(int j=m; j>=0; j--) {
            if(j>=A[i]) {
                dp[j] =dp[j] || dp[j-A[i]];
            }
        }
    }
        
    
    for(int i=m; i>=0; i--) {
        if(dp[i]) {
            return i;
        }
    }
    return 0;
}