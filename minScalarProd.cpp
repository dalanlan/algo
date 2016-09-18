/*
Problem A. Minimum Scalar Product
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minScalar(vector<int>& num1, vector<int>& num2) {
	sort(num1.begin(), num1.end());
	sort(num2.begin(), num2.end(), greater<int>());
	int sum = 0;
	for(int i=0; i<num1.size(); i++) {
		sum += num1[i]*num2[i];
	}
	return sum;
}

int main() {
	int T;
	cin >> T;
	for(int i=0; i<T; i++) {
		int n;
		cin>>n;
		vector<int> num1(n, 0);
		vector<int> num2(n, 0);
		
		for(int j=0; j<n; j++) {
			cin>> num1[j];
		}
		for(int j=0; j<n; j++) {
			cin >> num2[j];
		}
		int res = minScalar(num1, num2);
		cout<<"Case #"<<i+1<<": "<<res<<endl;
	}
	return 0;
}