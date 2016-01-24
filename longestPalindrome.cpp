
/*
lintCode : longest palindromic substring
http://www.lintcode.com/zh-cn/problem/longest-palindromic-substring/
*/


// solution 1: brute force + prune
class Solution {
public:
    /**
     * @param s input string
     * @return the longest palindromic substring
     */
    bool isParlindrom(string &s, int lo, int hi) {
    	while(lo <= hi) {
    		if(s[lo] != s[hi]) {
    			return false;
    		}
    		lo++;
    		hi--;
    	}
    	return true;
    }
    string longestPalindrome(string& s) {
    	
    	int right;
    	int len=s.length();
    	int count=0;
    	if(len <= 1){
    	    return s;
    	}
    	string res;
    	bool flag=false;

    	for(int i=0; i<len; i++) {
    		right = len-1;
    		flag = false;
    		while(flag==false && right > i){
    			while(right>i && s[right] != s[i]) right--;
    			
    			if(right > i && isParlindrom(s, i, right) && right-i+1>count) {
    				count = right-i+1;
    				res=s.substr(i, count);
    				flag = true;
    				
    			}
    			right--;
    			
    		}
    	}
    	return res;


    }
};

// solution 2: dynamic programming 

string longestPalindrome(string& s) {
	int len = s.length();
	if(len <= 1) {
		return s;
	}

	// dp[i][j] ~ whether s[i,j] is palindrome
	vector<vector<int>> dp(len, vector<int>(len, 0));

	// singleton: parlindrome
	for(int i=0; i<len; i++) {
		dp[i][i] = 1; 
	}

	int start = 0;
	int countMax = 1;
	for(int i=0; i<len-1; i++) {
		 if(s[i] == s[i+1]) {
		 	dp[i][i+1] = 1;
		 	countMax = 2;
		 	start = i;
		 }
	}

	// count: the length of palindrome substring
	
	int count;
	for(count = 3; count<=len; count++) {
		for(int i=0; i<len-count+1; i++) {
			int j = i+count-1;
			if(dp[i+1][j-1] == 1 && s[i] == s[j]) {
				dp[i][j] = 1;
				if(count > countMax) {
					countMax = count;
					start = i;
				}
			}
		}
	}
	return s.substr(start, countMax);
}

// solution 3: rewrite solution2

string longestPalindrome(string& s) {
	int len = s.length();
	if(len <= 1) {
		return s;
	}

	vector<vector<int>> dp(len, vector<int>(len, 0));

	int start = 0;
	int count = 0;
	for(int j = 0; j<len; j++) {
		for(int i = 0; i<=j; i++) {
			if(s[i] == s[j] && (j-i<=2 || dp[i+1][j-1])) {
				dp[i][j] = 1;
				if(j-i+1 > count) {
					count = j-i+1;
					start = i;
				}
			}
		}
	}
	return s.substr(start, count);
}

// solution 4: general idea
string longestPalindrome(string& s) {
	int len = s.length();
	if(len <= 1) {
		return s;
	}
	int start = 0;
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
			start = left;
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
				start = left;
				count = right-left+1;
			}
		} 

	}
	return s.substr(start, count);
}

// solution 5: 