
#include<iostream>
#include<string>
using namespace std;

int longestPalindrome(string& s) {
	int len = s.length();
	if(len <= 1) {
		return len;
	}
	//int start = 0;
	int count = 0;

	int left, right;
	for(int i=0; i<len; i++) {
		// odd
		left = i;
		right = i;
		while(left-1 >=0 && right+1 < len && s[left-1] == s[right+1]) {
			left--;
			right++;
		}
		if(right - left + 1 > count) {
			//start = left;
			count = right-left+1;
		} 

		// even
		if(i+1 < len && s[i] == s[i+1]) {
			left = i;
			right = i+1;
			while(left-1 >= 0 && right+1<len && s[left-1] == s[right+1]) {
				left--;
				right++;
			}
			if(right - left + 1 > count) {
				//start = left;
				count = right-left+1;
			}
		} 

	}
	return count;
	//return s.substr(start, count);
}

int main() {
	int n;
	cin>>n;
	string s;
	while(n--) {
		cin>>s;
		cout<<longestPalindrome(s)<<endl;

	}
	return 0;
}