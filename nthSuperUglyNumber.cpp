// Super Ugly Number

/*
Write a program to find the nth super ugly number.
Super ugly numbers are positive numbers whose all
prime factors are in the given prime list `primes`
of size k.
*/

// Sol 0: Rewrite Sol 1

struct group {
	int val;
	int factor;
	int index;
	group(int v, int f, int i):val(v), factor(f), index(i) {}
};



// Sol 1: priority_queue
private:
struct group {
	int val;
	int factor;
	int index;

	group(int v, int f, int i):val(v), factor(f), index(i) {}
};
class compare{
    public:
	bool operator()(group &g1, group &g2) {
		return g1.val > g2.val;
	}	
};
public:
int nthSuperUglyNumber(int n, vector<int>& primes) {
	int *ugly = new int [n];
	ugly[0] = 1;
	priority_queue<group, vector<group>, compare> pq;

	for(int i=0; i<primes.size(); i++) {
		pq.push({primes[i], primes[i], 0});
	}

	int index = 1;
	while(index < n) {
		auto tmp = pq.top();
		while(tmp.val == ugly[index-1]) {
			pq.pop();
			pq.push({tmp.factor*ugly[tmp.index+1], tmp.factor, tmp.index+1});
			tmp = pq.top();
		}
		ugly[index++] = tmp.val;
		pq.push({tmp.factor*ugly[tmp.index+1], tmp.factor, tmp.index+1});
		pq.pop();

	}
	
	return ugly[n-1];
}


// Sol 2: easy solution
// AC 
int nthSuperUglyNumber(int n, vector<int>& primes) {
	int k = primes.size();
	int *index = new int[k];
	int *res = new int[n];

	for(int i=0; i<k; i++) {
		index[i] = 0;
	}
	

	res[0] = 1;
	for(int i=1; i<n; i++) {
		res[i] = INT_MAX;
		for(int j=0; j<k; j++) {
			res[i] = min(res[i], primes[j]*res[index[j]]);
		}
		for(int j=0; j<k; j++) {
			if(res[i] == primes[j]*res[index[j]]) {
				index[j]++;
			}
		}
	}
	return res[n-1];

} 

// Sol 3: Rewrite Sol 2
int nthSuperUglyNumber(int n, vector<int>& primes) {
	vector<int> index(primes.size(), 0), ugly(n, INT_MAX);
	ugly[0] = 1;

	for(int i=1; i<n; i++) {
		for(int j=0;j<primes.size();j++) {ugly[i] = min(ugly[i], primes[j]*ugly[index[j]]);}
		for(int j=0;j<primes.size();j++) {index[j] += (ugly[i] == primes[j]*ugly[index[j]]);}
	}
	return ugly[n-1];
}