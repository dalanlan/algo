
/*
LintCode 413: Reverse an integer

Examples:
给定 x = 123，返回 321
给定 x = -123，返回 -321
*/

/**
 * @param n the integer to be reversed
 * @return the reversed integer
 */
int reverseInteger(int n) {
    long res = 0;
    int sign = (n<0)?-1:1;
    n *= sign;
    while(n) {
    	res = res*10 + n%10;
    	if(res > INT_MAX) {
    		return 0;
    	}
    	if(res*sign < INT_MIN) {
    		return 0;
    	}
    	n/=10;
    }
    return sign*res;
}