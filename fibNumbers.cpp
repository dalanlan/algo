// Dynamic Programming

// Set 1 Overlapping sub-problems 



// Fibonacci numbers

// solution 1: Top down
#define MAX 100
vector<int> v(MAX, 0);

int fib(int n) {
	if(v[n] == 0) {
		if(n <= 1) {
			v[n] = 1;
		}
		else {
			v[n] = fib(n-1) +fib(n-2);
		}
	}
	return v[n];	
}

// solution 2: Bottom up
int fib(int n) {
	
	if(n <= 1) {
		return 1;
	}
	vector<int> v(n+1, 0);
	v[0] = v[1] = 1;
	for(int i = 2; i <= n;i++) {
		v[i] = v[i-1] + v[i-2];
	}
	return v[n];
}

