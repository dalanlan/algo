
/*
Leetcode: Max Sum of Sub matrix no Larger than K
https://leetcode.com/problems/max-sum-of-sub-matrix-no-larger-than-k/

https://discuss.leetcode.com/topic/48875/accepted-c-codes-with-explanation-and-references/2
*/


class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
       if(matrix.empty()) {
           return 0;
       }
       int row = matrix.size();
       int col = matrix[0].size();
       
       int res = INT_MIN;
       
       for(int i=0; i<col; i++) {
           vector<int> dp(row, 0);
       
           for(int j=i; j<col; j++) {
               for(int c=0; c < row; c++) {
                   dp[c] += matrix[c][j];
               }
               res = max(res, maxSumSubarray(dp, k));
           }
       }
       return res;
       
    }
    
    int maxSumSubarray(vector<int> num, int k) {
        set<int> set;
        set.insert(0);
        
        int cum = 0, best = INT_MIN;
        
        for(int i=0; i<num.size(); i++) {
            cum+=num[i];
            
            auto it = set.lower_bound(cum-k);
            if(it != set.end()) {
                best = max(best, cum-*it);
            }
            set.insert(cum);
        }
        return best;
    }
};