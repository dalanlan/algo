/*

LintCode 428: myPow

*/

/**
 * @param x the base number
 * @param n the power number
 * @return the result
 */

double myPow(double x, int n) {
	if(n < 0) {
		return 1/myPow(x, -n);
	}
	if(n == 0) {
		return 1.0;
	}
	if(n == 1) {
		return x;
	}
	double res = myPow(x, n/2);

	if(n % 2 == 0) {
		return res*res;
	}
	else {
		return res*res*x;
	}
}
