/*
LeetCode: Rotate function
https://leetcode.com/problems/rotate-function/
*/

class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        long sz = A.size();
        if(sz == 0) {
            return 0;
        }
        long res = INT_MIN;
        vector<long> F(sz, 0);
        for(long i=0; i<sz; i++) {
            for(long j=0; j<sz; j++) {
                
                F[j] += i*A[(i+j)%sz];
                
            }
        }
        for(long i=0; i<sz; i++) {
            res = max(F[i], res);
        }
        return res;
        
    }
};