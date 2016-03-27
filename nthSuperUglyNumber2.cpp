
/*
LeetCode: super unly number

*/

/*
It's old and tricky.
We may come up with many solutions, yet it may has some overhead
Think harder
*/

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        
        // Use a vector to keep record of the index of the primes array
        int sz = primes.size();
        if(sz == 0 || n == 0) {
            return 0;
        }
        
        vector<int> index(sz, 0);
        vector<int> ugly(n, 0);
        
        ugly[0] = 1;
        for(int i = 1; i<n; i++) {
            int cand = INT_MAX;
            for(int j=0; j<sz; j++) {
                cand = min(cand, ugly[index[j]]*primes[j]);
            }
            ugly[i]=cand;
            for(int j=0; j<sz; j++) {
                index[j] += (cand == ugly[index[j]]*primes[j]);
            }
        }
        return ugly[n-1];
        
    }
};