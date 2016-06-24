
/*

Leetcode: perfect squares
https://leetcode.com/problems/perfect-squares/

*/


// TLE
class Solution {
public:
    bool isSquare(int n) {
        return (int)sqrt(n)*(int)sqrt(n) == n;
    }
    // dp
    int numSquares(int n) {
        vector<int> dp(n+1, INT_MAX);
        for(int i=1; i<=n; i++) {
            if(isSquare(i)) {
                dp[i] = 1;
            }
            else {
                for(int j=1; j<i; j++) {
                    if(isSquare(i-j)) {
                        dp[i] = min(dp[i], dp[j]+1);
                    }
                }
            }
        }
        return dp[n];
        
    }
};

// AC
// dp
int numSquares(int n) {
    vector<int> dp(n+1, INT_MAX);
    dp[0] = 0;

    for(int b=0; b <= n; b++) {
        for(int a=1; a*a+b<=n; a++) {
            int sum = a*a+b;
            dp[sum] = min(dp[sum], dp[b]+1);
        }
    }
    return dp[n];
}