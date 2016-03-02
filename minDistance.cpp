
/*
LintCode: edit distance
http://www.lintcode.com/zh-cn/problem/edit-distance/
*/

/*
This is a classical dp problem.
*/

// solution 1: recursive way
// TLE

int minDistance(string word1, string word2, int ind1, int ind2){
        if(ind1 == 0) {
            return ind2;
        }
        if(ind2 == 0) {
            return ind1;
        }
        if(word1[ind1-1] == word2[ind2-1]) {
            return minDistance(word1, word2, ind1-1, ind2-1);
        }
        return 1+min(minDistance(word1, word2, ind1-1, ind2),
                 min(minDistance(word1, word2, ind1, ind2-1), minDistance(word1, word2, ind1-1, ind2-1)));
    }
    int minDistance(string word1, string word2) {
        int len1 = word1.length(), len2 = word2.length();
        
        return minDistance(word1, word2, len1, len2);
        
    }


// solution 2: dp 
// This is very brilliant,
// the key point is you cannot tell
// exactly which way(insert, remove, replace) costs
// most without comparison.
int minDistance(string word1, string word2) {
	
	int len1 = word1.length(), len2 = word2.length();

	if(len1 == 0) {
		return len2;
	}
	if(len2 == 0) {
		return len1;
	}

	vector<vector<int>> dp=vector<vector<int>>(len1+1, vector<int>(len2+1, 0));
	for(int i=0; i<=len1; i++) {
		dp[i][0] = i;
	}
	for(int i=0; i<=len2; i++) {
		dp[0][i] = i;
	}

	for(int i=1; i<=len1; i++) {
		for(int j=1; j<=len2; j++) {
			if(word1[i-1] == word2[j-1]) {
				dp[i][j] = dp[i-1][j-1];
			}
			else {
				dp[i][j] = 1+ min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1]));
			}
		}
	}
	return dp[len1][len2];

} 