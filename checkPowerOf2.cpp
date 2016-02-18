
/*
LintCode: O(1) check power of 2
http://www.lintcode.com/zh-cn/problem/o1-check-power-of-2/
*/

bool checkPowerOf2(int n) {
	if(n<=0) return false;
	return (n&(n-1)) == 0;
}