
/*
LintCode: scramble string
http://www.lintcode.com/zh-cn/problem/scramble-string/

LeetCode: 
https://leetcode.com/problems/scramble-string/
*/

// solution 4: recursive + cache
// AC
bool isScramble(unordered_map<string, bool> &cache, string s1, string s2) {
	if(s1.length() != s2.length()) {
		return false;
	}
	int len = s1.length();
	if(len == 0) {
		return true;
	}

	if(len == 1) {
		return s1==s2;
	}

	if(cache.count(s1+s2)) {
		return cache[s1+s2];
	}
	bool res = false;

	for(int i=1; i<len; i++) {
		res = res || isScramble(cache, s1.substr(0, i), s2.substr(0, i)) && isScramble(cache, s1.substr(i), s2.substr(i));
		res = res || isScramble(cache, s1.substr(0, i), s2.substr(len-i)) && isScramble(cache, s1.substr(i), s2.substr(0, len-i));
	}
	return cache[s1+s2] = res;
}
bool isScramble(string s1, string s2) {

	unordered_map<string, bool> cache;
	return isScramble(cache, s1, s2);

}


// solution 3: recursive + graceful prone
// AC
// DONT KNOW WHY
bool isScramble(string s1, string s2) {
	

	// no need to sort 
	// just count the count of appearance of the characters
	int len1 = s1.length();
	int len2 = s2.length();
	if(len1 != len2) {
		return false;
	}
	if(len1 == 1) {
		return s1 == s2;
	} 

	vector<int> hash(26, 0);
	for(int i=0; i<len1; i++) {
		hash[s1[i]-'a']++;
	}
	for(int i=0; i<len2; i++) {
		hash[s2[i]-'a']--;
	}
	for(int i=0; i<26; i++) {
		if(hash[i] != 0) {
			return false;
		}
	}

	for(int i=1; i<len1; i++) {
		if(isScramble(s1.substr(0, i), s2.substr(0,i)) && isScramble(s1.substr(i), s2.substr(i))) {
			return true;
		}
		if(isScramble(s1.substr(0, i), s2.substr(len2-i)) && isScramble(s1.substr(i), s2.substr(0, len2-i))) {
			return true;
		}
	}
}

// solution 2: dp
// deal with the corner cases
// edge problems
bool isScramble(string &s1, string &s2) {
	/*
	To further improve the performance, we can use bottom-up DP, 
	which is O(N^4) complexity. Here we build a table isS[len][i][j], 
	which indicates whether s1[i..i+len-1] is a scramble of s2[j..j+len-1].
	*/

	if(s1.length() != s2.length()) {
		return false;
	}
	int len = s1.length();
	if(len == 1) {
		return (s1 == s2);
	}
	vector<vector<vector<bool>>> dp = vector<vector<vector<bool>>>(len+1, vector<vector<bool>>(len, vector<bool>(len, false)));

	//dp[0][*][*] = false 
	//dp[1][*][*] 

	for(int i=0; i<len; i++) {
		for(int j=0; j<len; j++) {
			dp[1][i][j] = (s1[i] == s2[j]);
		}
	}

	for(int l=2; l<=len; l++) {
		for(int i=0; i<=len-l; i++) {
			for(int j=0; j<=len-l; j++) {
				for(int k=1; k<l&&!dp[l][i][j]; k++) {
					dp[l][i][j] = dp[l][i][j] || (dp[k][i][j] && dp[l-k][i+k][j+k]);
					dp[l][i][j] = dp[l][i][j] || (dp[k][i][j+l-k] && dp[l-k][i+k][j]);
				}
			}
		}
	}
	return dp[len][0][0];
}


// solution 1: recursive
class Solution {
public:
    /**
     * @param s1 A string
     * @param s2 Another string
     * @return whether s2 is a scrambled string of s1
     */
     
     
    
    bool isScramble(string& s1, string& s2) {
        // Write your code here
        
        int len1 = s1.length();
        int len2 = s2.length();
        
        if(len1 != len2) {
            return false;
        }
        if(len1 == 1) {
            return s1 == s2;
        }
        string sorted1(s1);
        string sorted2(s2);
        sort(sorted1.begin(), sorted1.end());
        sort(sorted2.begin(), sorted2.end());
        if(sorted1 != sorted2) {
            return false;
        }
        if(len1 == 0) {
            return true;
        }
        bool res = false;
        string s11, s12, s21, s22;
        for(int i=1; i<len1 && !res; i++) {
            s11 = s1.substr(0,i);
            s12 = s1.substr(i);
            s21 = s2.substr(0,i);
            s22 = s2.substr(i);
            res = isScramble(s11, s21) && isScramble(s12, s22);
            if(!res) {
                s21 = s2.substr(0, len1-i);
                s22 = s2.substr(len1-i);
                res = isScramble(s11, s22) && isScramble(s12, s21);
            }
        }
        return res;
    }
};