
/*
Leetcode: number of digit one
https://leetcode.com/problems/number-of-digit-one/
*/

class Solution {
public:
    int countDigitOne(int n) {
        
        long base = 1;
        long count = 0;
        while(n/base>0) {
            long higher = n/(base*10);
            long cur = n/base%10;
            long lower = n%base;
            
            if(cur == 1) {
                count += higher*base + lower + 1;
            }
            else if(cur < 1) {
                count += higher * base;
            }
            else {
                count += (higher+1)*base;
            }
            base *= 10;
        }
        return count;
    }
};