
/*
LintCode: wildcard matching
http://www.lintcode.com/zh-cn/problem/wildcard-matching/
*/

// solution 1: greedy algorithm
class Solution {
public:
    /**
     * @param s: A string 
     * @param p: A string includes "?" and "*"
     * @return: A boolean
     */
    bool isMatch(const char *s, const char *p) {
        // write your code here
        
        int sLen = strlen(s);
        int pLen = strlen(p);
        
        int i=0, j=0;
        int star = -1;
        int mark = -1;
        while(i<sLen) {
            if(j<pLen && (p[j] == '?' || p[j] == s[i])) {
                i++;
                j++;
            }
            else if(j<pLen && p[j] == '*') {
                star = j;
                mark = i;
                j++;
            }
            else if(star != -1) {
                i=mark;
                mark++;
                j=star+1;
            }
            else {
                return false;
            }
        }
        
        while(j<pLen && p[j] == '*') {
            j++;
        }
        return j==pLen;
    }
};

// solution 2: greedy / recursive
// TLE
bool isMatch(string s, string p, int i, int j) {
	int sLen = s.length();
	int pLen = p.length();

	if(i == sLen) {
		return j == pLen;
	}

	if(j < pLen && (s[i] == p[j] || p[j] == '?')) {
		return isMatch(s, p, i+1, j+1);
	}

	if(j < pLen && p[j] == '*') {
		while(j < pLen && p[j] == '*') {
			j++;
		}
		while(i < sLen) {
			if(isMatch(s, p, i, j)) {
				return true;
			}
			i++;
		}
		return isMatch(s, p, i, j);
	}
	return false;
}
bool isMatch(string s, string p) {
	return isMatch(s, p, 0, 0);
}


// solution 3: dp