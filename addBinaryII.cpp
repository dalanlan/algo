
/*
Lintcode 408 : additive in binary representation

Given two strings which represents two ops, 
return their sum, in binary of course.

*/



/**
 * @param a a number
 * @param b a number
 * @return the result
 */
string addBinary(string& a, string& b) {
    // Write your code here

    int len1 = a.length(), len2 = b.length();
    // a == null
    if(len1 == 0) {
    	return b;
    }
    if(len2 == 0) {
    	return a;
    }

    string res;
    int val, carry=0;
    int i=len1-1, j=len2-1;
    while(i>=0 || j >= 0) {
    	val = (i>=0?(a[i--]-'0'):0) + (j>=0?(b[j--]-'0'):0)+carry;
    	carry = val/2;
    	res = to_string(val%2) + res;
    }
    if(carry > 0) {
    	res = to_string(carry) + res;
    }
    return res;
    

}