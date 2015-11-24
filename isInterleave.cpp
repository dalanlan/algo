//Interleaving String
/*
 Given s1, s2, and s3, find out whether s3 
 is formed by the interleaving of s1 and s2.
*/

// sol 1: recusive solution 
unordered_set<string> mySet;
bool isInterleave(string s1, string s2, string s3) {
	if(s1.length() == 0 && s2.length() == 0 && s3.length() == 0) {
		return true;
	}
	if(mySet.find(s1+" "+s2) != mySet.end()) {
		return false;
	}
	
	if(s1.length() > 0 && s3.length() >0 && s1[0] == s3[0]) {
		if(isInterleave(s1.substr(1,s1.length()-1), s2, s3.substr(1, s3.length()-1))) 
			return true;
	}
	if(s2.length() > 0 && s3.length() >0 && s2[0] == s3[0]) {
		if(isInterleave(s1, s2.substr(1, s2.length()-1), s3.substr(1, s3.length()-1)))
			return true;
	}

	mySet.insert(s1+" "+s2);
	return false;
}

// solution 2: dp

bool isInterleave(string s1, string s2, string s3) {
	int len1 = s1.length();
	int len2 = s2.length();
	int len3 = s3.length();

    if(len1 + len2 != len3) {
        return false;
    }
    if(len1 == 0) {
        return s2 == s3;
    }
    if(len2 == 0) {
        return s1 == s3;
    }
    
	if(len1 == 0 && len2 == 0 && len3 == 0) {
		return true;
	}
	vector<vector<bool>> v(len1+1, vector<bool>(len2+1, false));
    v[0][0] = true;
	for(int i=0; i <= len1; i++) {
		for(int j=0; j <= len2; j++) {
			// We dont need this 'cause 
			// if(j >0 && i == 0 && s2[j-1] == s3[j-1]) {
			// 	v[0][j] = v[0][j-1];
			// }
			// if(i>0 && j == 0 && s1[i-1] == s3[i-1]  ) {
			// 	v[i][0] = v[i-1][0];
			// }
			if(i > 0 && s1[i-1] == s3[i+j-1] && v[i-1][j]) {
				v[i][j] = true;
			}
			if(j > 0 && s2[j-1] == s3[i+j-1] && v[i][j-1]) {
				v[i][j] = true;
			}
		}
	}
	return v[len1][len2];
}