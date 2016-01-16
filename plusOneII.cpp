
/*
Lintcode 407: Plus one
*/

/**
 * @param digits a number represented as an array of digits
 * @return the result
 */
vector<int> plusOne(vector<int>& digits) {
	// Write your code here
	vector<int> res;
	int cur, carry=1;
	for(int i=digits.size()-1; i>=0; i--) {
		cur = digits[i]+carry;
			carry = cur/10;
		res.insert(res.begin(), cur%10);
	}
	if(carry>0) {
	    res.insert(res.begin(), carry);
	}
	return res;
}
