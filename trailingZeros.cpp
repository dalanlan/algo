
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


int trailingZeroes(int n) {
    long base = 5;
    long count = 0;

    while(n/base > 0) {
        cout += n/base;
        base *= 5;
    }
    return cout;
}

int trailingZeroes(int n) {
    int count  = 5;
    n /= 5;
    while(n) {
        count += n;
        n/=5;
    }
    return count;
}