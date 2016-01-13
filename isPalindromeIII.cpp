
/*
LintCode 415: Valid palindrome

Given a string, determine whether it is a 
valid palindrome.
*/
bool isEqual(char this, char that) {
	return this==that || this-'A' == that-'a' || this-'a' == that-'A';
}

bool isPalindrome(string& s) {
	int sz = s.length();
	int lf = 0, rt = sz-1;

	while(lf <= rt) {
		while(s[lf] == ' ' && lf < sz) lf++;
		if(lf == sz) {
			return true;
		}
		while(s[rt] == ' ' && rt >= 0) rt--;
		if(rt < 0) {
			return true;
		}
		if(!isEqual(s[lf], s[rt])) {
			return false;
		}
		lf++;
		rt--;
	}	
	return true;
}