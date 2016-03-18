
/*
LintCode: trailing zeros
http://www.lintcode.com/zh-cn/problem/trailing-zeros/
*/
/* idea: count the number of appearance of 5
note that 5*5*...*5 may have extra 5
http://www.geeksforgeeks.org/count-trailing-zeroes-factorial-number/
*/

class Solution {
 public:
    // param n : description of n
    // return: description of return 
    long long trailingZeros(long long n) {
        
        long long res=0;
        long long base = 5;
        while(n/base) {
            res += n/base;
            base*=5;
        }
        return res;
        
    }
};
