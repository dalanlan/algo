// Multiple Strings

/*
Given two numbers represented as strings, return
multiplication of the numbers as a string. 
Note: The numbers can be arbitrarily large and 
non-negative.
*/

string multiply(string num1, string num2) {
	int sz1 = num1.length(), sz2 = num2.length();
	int* res = new int[sz1+sz2];
	for(int i=0; i<sz1+sz2; i++) {
		res[i] = 0;
	}

	int pos1, pos2, sum;
	for(int i=sz1 - 1; i >= 0; i--) {
		for(int j=sz2 -1; j >= 0; j--) {
			pos1 = i+j;
			pos2 = i+j+1;

			sum = (num1[i]-'0')*(num2[j]-'0') + res[pos2];
			res[pos1] += sum/10;
			res[pos2] = sum%10; 
		}
	}

	string ans("");
	
	for(int i=0;i<sz1+sz2;i++) {
		if(!(ans.length() == 0 && res[i] == 0)) {
    		ans += res[i]+'0';
		}
	}
	if(ans.length() == 0) return "0"; 
	else return ans;
	

}