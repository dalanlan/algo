// Scramble string
// Dynamic programming 
// s1[0,i] == s2[0,i] && s1[i+1,len] == s2[i+1,len]
// Or s1[0,i] == s2[len-i, len] && s1[len-i, len] == s2[i+1, len]

#include <string>
#include <iostream>
using namespace std;

// solution :TLE
bool isScramble(string s1, string s2) {
	if(s1 == s2) {
		return true;
	}

	if(s1.length() != s2.length()) {
		return false;
	}
	
	int len = s1.length();
	if(len == 1)
	    return s1==s2;
	    
	for(int i = 1; i < len; i++) {
		if(isScramble(s1.substr(0, i), s2.substr(0,i)) && 
		isScramble(s1.substr(i,len-i), s2.substr(i,len-i))) {
			return true;
		}
		
		if(isScramble(s1.substr(0,i), s2.substr(len - i,i)) &&
		isScramble(s1.substr(i,len-i), s2.substr(0,len-i))) {
			return true;
		}

	}
	return false;



}


int main() {

	string s1("abcdefghijklmnopq");
	string s2("efghijklmnopqcadb");

	cout<<isScramble(s1, s2)<<endl;
	return 0;
}

// AC

bool isScramble(string s1, string s2) {
	int len = s1.length();
	if(len == 0) {
		return false;
	}
	if(len == 1) {
		return s1 == s2;
	}

	bool isS[len+1][len][len];

	//isS[0][*][*]: ignored 
	//isS[1][i][j]

	for(int i=0; i<len;i++) {
		for(int j=0;j<len;j++) {
			isS[1][i][j]=(s1[i] == s2[j]);
		}
	}

	for(int l=2; l <= len; l++) {
		for(int i=0; i<=len-l; i++) {
			for(int j=0; j<=len-l; j++) {
				isS[l][i][j] = false;
				for(int k=1; k<l && !isS[l][i][j];k++) {
					isS[l][i][j] = isS[l][i][j] || (isS[k][i][j] && isS[l-k][i+k][j+k]);
					isS[l][i][j] = isS[l][i][j] || (isS[k][i][j+l-k] && isS[l-k][i+k][j]);
				}
			}
		}
	}
	return isS[len][0][0];

}