/*
LeetCode: count numbers with unique digits
https://leetcode.com/problems/count-numbers-with-unique-digits/
Given a non-negative integer n, count all numbers with unique digits, x, where 0 ≤ x < 10^n.
*/

// dynamic programming
// f(1) = 10, ..., 
// f(k) = 9 * 9 * 8 * ... (9 - k + 2) [The first factor is 9 because a number cannot start with 0].

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0) {
            return 1;
        }
        vector<int> dp(n+1, 0);
        int sum = 10;
        dp[1] = 10;
        
        for(int i=2; i<=n; i++) {
            dp[i] = i==2?81:dp[i-1]*(9-i+2);
            sum += dp[i];
        }
        return sum;
        
    }
};

// dp
// dont use extra space
// label the current result
int countNumbersWithUniqueDigits(int n) {
	if(n == 0) {
		return 1;
	}

	int res = 10;
	int current = 9;
	int next = 9;
	while(n-- > 1 && next > 0) {
		current *= next;
		res += current;
		next--;
	}
	return res;
}

// 
int counter = 0;
int countNumbersWithUniqueDigits(int n) {
	int elem = 0;
	vector<bool> visited(n, elem, 0);	
}

void count(int n, int elem, int index) {
	counter++;


	for(int i=index; i<n; )
}