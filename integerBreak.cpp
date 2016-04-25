
/*
LeetCode: integer break
https://leetcode.com/problems/integer-break/
*/

class Solution {
public:
    int integerBreak(int n) {
        vector<int> base = {0, 1, 1, 2, 4};
        if(n <= 4) {
            return base[n];
        }
        if(n % 3 == 0) {
            return pow(3, n/3);
        }
        if(n % 3 == 1) {
            return 4*pow(3, n/3-1);
        }
        
        return 2*pow(3, n/3);
        
        
    }
};