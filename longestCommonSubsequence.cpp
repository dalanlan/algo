// Dynamic Programming

// Set 4 Longest Common Subsequence

/* Given two sequences, find the length of
longest subsequence present in both of them.
A subsequence is a sequence that appears in 
the same relative order, but not necessarily
contiguous. 
*/


/*
if(X[m-1] == Y[n-1]) 
L(X[0, ..., m-1], Y[0,...,n-1])=L(X[0,..,m-2], Y[0,...,n-2])+1

else
L(X[0, ..., m-1], Y[0,...,n-1])=
max(L(X[0,...,m-2], Y[0,...,n-1]), L(X[0,...,m-1]), Y[0,...,n-2]))
*/


int lcs(char *X, char *Y, int m, int n){
	if(m == 0 || n == 0) {
		return 0;
	}
	if(X[m-1] == Y[n-1]) {
		return lcs(X, Y, m-1, n-1) +1;
	}
	else {
		return max(lcs(X,Y,m-1,n), lcs(X,Y,m,n-1));
	}

}