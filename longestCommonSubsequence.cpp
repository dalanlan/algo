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


// Solution 1: iterative
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


// Solution 2: DP
// Use an array to store the result

// known var m,n; 
// length
//return array[m][n];
int array[m+1][n+1];

int lcs(char *X, char *Y, int m, int n) {
	for(int i=0; i<=m; i++) {
		array[i][0] = 0;
	}
	for(int i=0; i<=n; i++) {
		array[0][i] = 0;
	}

	for(int i=1; i<=m; i++) {
		for(int j=1; j<=n; j++) {
			if(X[i] == Y[j]) {
				array[i][j] = array[i-1][j-1]+1;
			}
			else {
				array[i][j] = max(array[i-1][j], array[i][j-1]);
			}
		}
	}
	return array[m][n];
} 

// Solution 3: extension 
// lcs + print lcs
int array[m+1][n+1];
enum dir {LEFT, UP, LEUP};
dir prev[m+1][n+1];
int lcs(char *X, char *Y, int m, int n) {
	for(int i=0; i<=m; i++) {
		array[i][0] = 0;
	}
	for(int i=0; i<=n; i++) {
		array[0][i] = 0;
	}
	for(int i=1; i<=m; i++) {
		for(int j=1; j<=n; j++) {
			if(X[i] == Y[j]) {
				array[i][j] = array[i-1][j-1]+1;
				prev[i][j] = LEUP;
			}
			else if(array[i][j-1] > array[i-1][j]) { // left
				array[i][j] = array[i][j-1];
				prev[i][j] = LEFT;
			}
			else { // 
				array[i][j] = array[i-1][j];
				prev[i][j] = UP;	
			}
		}
	}
	return array[m][n];
	printLCS(m,n); // recursive
}

void printLCS(char *X, char *Y, int i,int j) {
	if(i == 0 || j == 0) {
		return;
	}

	if(prev[i][j] == LEUP) {
		printLCS(i-1, j-1);
		cout<<X[i];
	}
	else if(prev[i][j] == LEFT) {
		printLCS(i, j-1);
	}
	else {
		printLCS(i-1,j);
	}
}