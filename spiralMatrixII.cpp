
/*
Leetcode: spiral matrix ii
https://leetcode.com/problems/spiral-matrix-ii/
*/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        vector<vector<int>> dp =  vector<vector<int>>(n, vector<int>(n, 0));
        int val = 1;
        int cnt = 0;
        
        while(cnt<=(n-1)/2) {
            for(int i=cnt; i<n-cnt; i++) {
                dp[cnt][i]=val++;
            }
            for(int i=cnt+1; i<n-cnt; i++) {
                dp[i][n-1-cnt]=val++;
            }
            if(cnt == n/2) {
                break;
            }
            for(int i=n-cnt-2; i>=cnt; i--) {
                dp[n-1-cnt][i] = val++;
            }
            for(int i=n-cnt-2; i>cnt; i--) {
                dp[i][cnt] = val++;
            }
            cnt++;
        }
        return dp;
    }
};