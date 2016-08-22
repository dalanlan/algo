// Add binary

/*
Given two binary strings, return their sum.
*/


string addBinary(string a, string b) {
	if(a.length() == 0) {
		return b;
	}
	if(b.length() == 0) {
		return a;
	}

	int i=a.length()-1, j = b.length()-1;
	string res(max(i,j)+1, '0');
	int cur = 0;
	bool carry=false;

	while(i>=0 || j>=0) {
		cur = (i >= 0 ? a[i--]-'0':0) + (j >= 0 ? b[j--]-'0' : 0)+ carry;
		res[max(i,j)+1] = cur%2 +'0';
		carry = (cur>1);
	}
	if(carry) {
		res = "1"+res;
	}
	return res;

}


class Solution {
public:
    string addBinary(string a, string b) {
        
        int aLen=a.size(), bLen=b.size();
        int i=aLen-1, j=bLen-1;
        
        string res("");
        int carry = 0;
        
        while(i >= 0 || j >= 0 || carry != 0) {
            int dig = carry + (i>=0?a[i--]-'0':0)+(j>=0?b[j--]-'0':0);
            carry = dig/2;
            res = to_string(dig%2)+res;
            
            
        }
        return res;
    }
};