
/*
LintCode : longest common substring
Given two strings, find out the longest common substring,
return its length.
*/

/*
Please distinguish with longest common subsequence problem,
which doesn't require the string to stick together
*/

/*
This issue is classic and involves a solution with suffix tree O(m+n) or 
dynamic programming O(m*n)

1. wiki: https://en.wikipedia.org/wiki/Longest_common_substring_problem
2. ref suffix tree: http://www.drdobbs.com/architecture-and-design/algorithm-alley/184404588
*/

class Solution {
public:    
    /**
     * @param A, B: Two string.
     * @return: the length of the longest common substring.
     */
    int longestCommonSubstring(string &A, string &B) {
        int m = A.length(), n = B.length();
        int res = 0;
        // table[i][j]
        int table[m+1][n+1];
        for(int i=0; i<=m; i++) {
        	table[i][0] = 0;
        }
        for(int j=0; j<=n; j++) {
        	table[0][j] = 0;
        }

        for(int i=1; i<=m; i++) {
        	for(int j=1; j<=n; j++)	{
        		if(A[i-1] == B[j-1]) {
        			table[i][j] = table[i-1][j-1]+1;
        		}
        		else {
        			table[i][j] = 0;
        		}
        		if(res < table[i][j]) {
        			res = table[i][j];
        		}
        	}
        }

        return res;

    }
};

// solution 2: dp
    int longestCommonSubstring(string &A, string &B) {
        int m = A.length();
        int n = B.length();
        
        vector<int> dp(n+1, 0);
        int res = 0;
        
        for(int i=1; i<=m; i++) {
            for(int j=n; j>0; j--) {
                if(A[i-1] == B[j-1]) {
                    dp[j] = dp[j-1]+1;
                }
                else {
                    dp[j] = 0;
                }
            
                res = max(res, dp[j]);
            }
            
        }
        return res;
    }

/*
suffix tree ref: http://www.drdobbs.com/architecture-and-design/algorithm-alley/184404588
May solve "longest substring without repeating characters???


*/

