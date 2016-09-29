/*
Leetcode: binary watch
https://leetcode.com/problems/binary-watch/
*/
class Solution {
public:
    
    void read(vector<int>& dp, vector<string> &res, int num, int n, int ind) {
        if(n == num) {
            string rs("");
            int dec = 0;
            for(int i=0; i<=3; i++) {
                if(dp[i]) dec += pow(2, i);
                
            }
            if(dec >= 12) {
                return;
            }
            rs += to_string(dec);
            rs += ":";
            
            dec = 0;
            for(int i=4; i<10; i++) {
                if(dp[i]) dec += pow(2, i-4);
            }
            if(dec >= 60) {
                return;
            }
            if(dec < 10) {
                rs += "0";
            }
            
            rs += to_string(dec);
        
            res.push_back(rs);
            
        }
        else {
            for(int i=ind; i<10; i++) {
                dp[i] = 1;
                read(dp, res, num, n+1, i+1);
                dp[i] = 0;
            }
            
        }
    }
    vector<string> readBinaryWatch(int num) {
        vector<string> res;
        vector<int> dp(10, 0);
        
        read(dp, res, num, 0, 0);
        
        
        
        return res;
        
    }
};