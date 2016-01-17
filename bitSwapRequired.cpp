
/*
LintCode 181: Convert integer A to B
Write a function to determine the number of bits required to convert integer A to integer B.

Cracking the coding interview Q5.5

Example: return 2 to convert 31 to 14
(31)10=(11111)2
(14)10=(01110)2
*/

int countOneInBinary(int n) {
	int count = 0;
	while(n) {
		count++;
		n = n&(n-1);
	}
	return count;
}
int bitSwapRequired(int a, int b) {
	
	return countOneInBinary(a^b);
}