// Valid Palindrome
/*
Given a string, determine if it is a palindrome, 
considering only alphanumeric characters and 
ignoring cases.
*/

    bool isAlphanumeric(char c) {
        return (c>=65 && c <= 90) || (c>=97 && c<=122) || (c>=48 && c<=57);
    }
    bool isPalindrome(string s) {
	int sz = s.length();
	if(sz <= 1) {
		return true;
	}

	int head = 0, tail=sz-1;

	while(head <= tail) {
		while(!isAlphanumeric(s[head]) && head < sz-1 ) {
			head ++;
		}
		while(!isAlphanumeric(s[tail]) && tail > 0) {
			tail --;
		}
		
		if(!isAlphanumeric(s[head]) || !isAlphanumeric(s[tail])) {
		    break;
		}
		if(s[head] == s[tail] || abs(s[head]-s[tail]) == 32) {
			head++;
			tail--;
		}
		else{
			return false;
		}
	}	
	return true;

}