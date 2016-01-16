// Plus One

/*
Given a non-negative number represented as an
array of digits, plus one to the number. The 
digits are stored such that the most significant
digit is at the head of the list.
*/


vector<int> plusOne(vector<int>& digits) {
	int sz = digits.size();
	if(sz == 0) {
		return vector<int>{1};
	}

	int val = digits[sz-1]+1;
	int carry = val/10;
	digits[sz-1] = val%10;

	for(int i=digits.size()-2; i >= 0; i--) {
		val = digits[i] + carry;
		digits[i] = val % 10;
		carry = val/10;
	}
	if(carry == 0) {
		return digits;
	}
	else {
		vector<int> res;
		res.push_back(carry);
		for(int i=0;i<digits.size();i++) {
			res.push_back(digits[i]);
		}
		return res;
	}
}


// Sol 2: rewrite 
// neat and clean
vector<int> plusOne(vector<int>& digits) {
	for(int i=digits.size()-1; i >= 0; i--) {
		if(digits[i] < 9) {
			digits[i]++;
			return digits;
		}
		else {
			digits[i] = 0;
			if(i == 0) {
				vector<int> v; 
				v.push_back(1);
				for(int i = 0;i < digits.size();i++) {
					v.push_back(digits[i]);
				}
				return v;
			}
		}
	}
	
}