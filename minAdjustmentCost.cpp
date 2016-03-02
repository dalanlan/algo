
/*
LintCode: minimum adjustment cost

*/

// solution 1: recursive solution
// TLE

class Solution {
public:
    /**
     * @param A: An integer array.
     * @param target: An integer.
     */
    int MinAdjustmentCost(vector<int> A, int target) {
        // write your code here
        
        if(A.size() == 0) {
            return 0;
        }
        vector<int> B; 
        
        return minAdjustmentCost(A, B, target, 0);
    }
    
    int minAdjustmentCost(vector<int> &A, vector<int> &B, int target, int ind) {
        if(ind >= A.size()) {
            return 0;
        }
        int diff = 0;
        int minNum = INT_MAX;
        for(int i=1; i<=100; i++) {
            if(ind > 0 && abs(B[ind-1] - i) > target) {
                continue;
            }
            B.push_back(i);
            diff = abs(i-A[ind]) + minAdjustmentCost(A, B, target, ind+1);
            minNum = min(minNum, diff);
            B.pop_back();
            
        }
        return minNum;
    }
};


// solution 2: recursive solution
// add up cache

class Solution {
public:
    /**
     * @param A: An integer array.
     * @param target: An integer.
     */
    int MinAdjustmentCost(vector<int> A, int target) {
        // write your code here
        
        if(A.size() == 0) {
            return 0;
        }
        vector<int> B; 
        
        vector<vector<int>> cache = vector<vector<int>>(A.size(), vector<int>(101, INT_MAX));
        return minAdjustmentCost(A, B, target, cache, 0);
    }
    
    int minAdjustmentCost(vector<int> &A, vector<int> &B, int target, vector<vector<int>> &cache, int ind) {
        if(ind >= A.size()) {
            return 0;
        }
        int diff = 0;
        int minNum = INT_MAX;
        for(int i=1; i<=100; i++) {
            if(ind > 0 && abs(B[ind-1] - i) > target) {
                continue;
            }
            if(cache[ind][i] != INT_MAX) {
                diff = cache[ind][i];
                minNum = min(diff, minNum);
                continue;
            }
            
            B.push_back(i);
            diff = abs(i-A[ind]) + minAdjustmentCost(A, B, target, cache, ind+1);
            cache[ind][i] = diff;
            minNum = min(minNum, diff);
            B.pop_back();
            
        }
        return minNum;
    }
};

int MinAdjustmentCost(vector<int> A, int target) {
	int sz = A.size();
	if(sz == 0) {
		return 0;
	}

	int res = INT_MAX;

	//dp[i][j]: the minimum cost to change ith element to j
	vector<vector<int>> dp = vector<vector<int>>(sz, vector<int>(101, INT_MAX));

	for(int i=0; i<sz; i++) {
		for(int j=1; j<=100; j++) {
			if(i == 0) {
				dp[i][j] = abs(j-A[i]);
			}
			else {
				
				for(int k=1; k<=100; k++) {
					if(abs(j-k) > target) {
						continue;
					}
					dp[i][j] = min(dp[i][j], dp[i-1][k] + abs(A[i]-j));	
				}
			}
			
		}
	}

	// loop
	for(int i=1; i<=100; i++) {
		res = min(res, dp[sz-1][i]);
	}
	return res;

}