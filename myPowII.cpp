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

// rewrite myPow in a neat way

double myPow(double x, int n) {
	bool neg = false;
	if(n < 0) {
		neg = true;
	}
	if(n == 1) {
		return x;
	}
	double res = 1;
	while(n > 1) {
		if(n % 2 == 0) {
			res *= res;
		}
		else {
			res *= res;
			res *= x;
		}
		n /= 2;
	}
	if(neg) {
		return 1/res;
	}	
	else 
		return res;
}

// rewrite myPow
// the tricks 
// n*(-1) could overflow -> convert to long 
// n >>= 1 could fail when it's negative -> convert to positive number
// n&1 == 1 to determine whether it's odd/even always work


double myPow(double x, int n) {
	long m = n>=0?n:-(long)n;

	double res =1.0;
	while(m != 0) {
		if(m & 1== 1) {
			res *= x;
		}
		x *= x;
		m >>= 1;
	}
	return n>=0?res:1/res;
}