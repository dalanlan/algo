
/*
LintCode: fast power
http://www.lintcode.com/zh-cn/problem/fast-power/
*/

// tip 1: overflow -- long type instead of int type
// tip 2: divide n

class Solution {
public:
    /*
     * @param a, b, n: 32bit integers
     * @return: An integer
     */
    int fastPower(int a, int b, int n) {
        // write your code here
        
        
        // recursive
        // conquer
        // binary
        
        if(n==0) {
            return 1%b;
        }
        if(n==1) {
            return a%b;
        }
        long half = (long)fastPower(a, b, n/2);
        if(n%2==0) { // even
            return (half*half)%b;
        }
        if(n%2==1) {
            return (((half*half)%b)*(a%b))%b;
        }
        }
};