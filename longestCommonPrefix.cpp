
/*
LintCode : longest common prefix
http://www.lintcode.com/zh-cn/problem/longest-common-prefix/

Given k strings, find out longest common prefix (LCP) among them.

*/

// basic version
// Given two strins, find out the longest common prefix between them two.
string longestCommonPrefix(string a, string b) {
	int m=a.length();
	int n=b.length();

	int pos = 0;
	while(pos < m && pos < n) {
		if(a[pos] == b[pos]) {
			pos++;
		}
	}
	return a.substr(0, pos);
}

class Solution {
public:    
    /**
     * @param strs: A list of strings
     * @return: The longest common prefix
     */
    string longestCommonPrefix(vector<string> &strs) {
        // brute force
        if(strs.size() == 0) {
        	return "";
        }
        string prefix=strs[0];

        for(int i=1; i<strs.size(); i++) {
        	int j = 0;
        	while(j < strs[i].length() && j<prefix.length() && strs[i][j] == prefix[j]) {
        		j++;
        	}
        	prefix = prefix.substr(0,j);
        }
        return prefix;
    }
};