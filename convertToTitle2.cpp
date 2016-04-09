
/*
Leetcode: excel sheet column title
https://leetcode.com/problems/excel-sheet-column-title/
*/


// solution : much more clean
string convertToTitle(int n) {
    return n==0?"":convertToTitle(n/26)+(char)(--n%26+'A');
}

string convertToTitle(int n) {
	string res;
	int pos = 0;
	while(n) {
		int rem = n% 26;
		if(rem == 0) {
			rem = 26;
		}
		res = 'A' + rem -1 + res;
		n /= 26;
	}
	return res;
}
