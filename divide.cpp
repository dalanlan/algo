
/*
LintCode: divide two integers
http://www.lintcode.com/zh-cn/problem/divide-two-integers/#
*/

class Solution {
public:
    /**
     * @param dividend the dividend
     * @param divisor the divisor
     * @return the result
     */
    int divide(int dividend, int divisor) {

        long a=abs((long)dividend);
        long b=abs((long)divisor);
        
        long res = 0;
        while(a>=b) {
            for(long tmp=b, cnt = 1; tmp <= a; tmp <<= 1, cnt <<= 1) {
                a -= tmp;
                res += cnt;
            }
        }
        bool isNeg = (dividend >0 && divisor <0) || (dividend < 0 && divisor >0);
        res *= isNeg?-1:1;
        if(res > INT_MAX || res < INT_MIN) {
            return INT_MAX;
        }
        return res;
        
        
    }
};