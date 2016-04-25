
/*
One edit distance

Given two strings S and T, determine if they are both 
one edit distance apart.
*/

bool isOneEditDistance(string s, string t) {
	if(s.length() == 0 && t.length() == 0) {
		return false;
	}
	if(s.length() == 0) {
		return t.length() == 1;
	}
	if(t.length() == 0) {
		return s.length() == 1;
	}
	if(abs(s.length() - t.length()) > 1) {
		return false;
	}

	int i = 0, j = 0;
	int count = 0;
	while(i < s.length() && j < t.length()) {
		if(s[i] != t[j]) {
			count++;
			if(count > 1) {
				return false;
			}
			if(s.length() > t.length()) {
				i++;
			}
			else if(t.length() > s.length()) {
				j++;
			}
			else {
				i++;
				j++;
			}

		}
		else {
			i++;
			j++;
		}
	}
	if(i<s.length() || j<t.length) {
		count++;
	} 
	return count==1;
}