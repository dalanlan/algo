
/*
365: How many 1s in the binary representation

Count the number of 1s in the binary representation
of a 32-bit int

*/
    /**
     * @param num: an integer
     * @return: an integer, the number of ones in num
     */


// solution 1: simple method
// Look through all bits in an integer. Check if a bit 
// is set and if it's then increment the set bit count.
// cannot deal with negative number
// http://www.geeksforgeeks.org/count-set-bits-in-an-integer/
int countOnes(unsigned int num) {
	int count = 0;
	while(num) {
		if(num & 1) {
			count++;
		}
		num >>= 1;
	}
	return count;
}
// solution 2: 
int countOnes(int num) {
	int count = 0;

	while(num != 0) {
		count++;
		num &= num-1;
	}
	return count;
}
