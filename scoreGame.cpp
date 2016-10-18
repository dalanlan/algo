

#include <iostream>
#include <fstream>
#include <string.h>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cassert>
#include <list>
#include <iomanip>
#include <math.h>
#include <deque>
#include <utility>
#include <map>
#include <set>
#include <bitset>
#include <numeric>
#include <climits>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <sstream>

using namespace std;


#define mpr make_pair
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <double, double> pdd;
typedef vector <int> vi;
typedef vector <ll> vll;
typedef vector <double> vd;
typedef vector <string> vs;
typedef map <string, int> mpsi;
typedef map <double, int> mpdi;
typedef map <int, int> mpii;

long long pow(long long n, long long m, long long mod = 0){
	if(m < 0) return 0;
	long long ans = 1 % mod;
	long long k = n;
	while(m){
		if(m & 1) {
			ans *= k;
			if(mod) ans %= mod;
		}
		k *= k;
		if(mod) k %= mod;
		m >>= 1;
	}
	return ans;
}

int calcSum(deque<int> &deq) {
	int sum = 0;
	for(deque<int>::iterator it = deq.begin(); it != deq.end(); it++) {
		sum += *it;
	}
	return sum;
}

int score(deque<int> &deq) {
	if(deq.size() < 2) {
		return 0;
	}
	
	if(deq.size() == 2) {
		int fr = deq.front();
		int ba = deq.back();
		return fr>=ba?fr:ba;
	}

	int sum = calcSum(deq);

	deque<int> pollFirst(deq);
	pollFirst.pop_front();

	int cand1 = sum - score(pollFirst);

	deque<int> pollLast(deq);
	pollLast.pop_back();

	int cand2 = sum - score(pollLast);

	return cand1>cand2?cand1:cand2;

}

int calcSum2(vector<int> &num, int start, int end) {
	int sum = 0;
	for(int i=start; i<=end; i++) {
		sum += num[i];
	}
	return sum;
}


int score2(vector<int> &num, vector<vector<int>> &dp, int start, int end) {
	
	if(end - start == 0) {
		return num[start];
	}

	if(dp[start][end] != INT_MAX) {
		return dp[start][end];
	}

	if (end - start == 1) {
		int lo = num[start];
		int hi = num[end];
		int rr = max(lo, hi);
		dp[start][end] = rr;
		return rr;
	}

	int sum = calcSum2(num, start, end);


	int result1 = sum - score2(num, dp, start+1, end);
	int result2 = sum - score2(num, dp, start, end-1);
	int mres = max(result1, result2);
	dp[start][end] = mres;
	return mres;

}

int main() {
	int N;
	cin >> N;

	int sum = 0;
	vector<int> num(N, 0);
	for(int i=0; i<N; i++) {
		cin >> num[i];
		sum += num[i];
	}
	vector<vector<int>> dp(N, vector<int>(N, INT_MAX));
	// deque<int> deq(num.begin(), num.end());

	// cout<<score(deq)<<endl;
	// cout<<sum - score(deq)<<endl;

	int res = score2(num, dp, 0, N-1);
	cout << res <<endl;
	cout << sum - res<<endl;
	return 0;

}


// ==================================================


// solution 2:

int sum(vector<int>&num, int i, int j) {
	int sum = 0;
	
}
int main() {

	int n;
	cin >> n;
	vector<int> num(n, 0);

	for(int i=0; i<n; i++) {
		cin >> num[i];
	}
}