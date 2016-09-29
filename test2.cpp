
/*

Test preparation

*/
#include <iostream>
using namespace std;

int main() {
	int all = 0;
	int odd = 0;
	int even = 0;
	for(int i=0; i<=100; i++) {
		all += i;
		if(i&1) {
			odd += i;
		}
		else {
			even += i;
		}
	}
	cout<<"All:"<<all<<endl;
	cout<<"Even:"<<even<<endl;
	cout<<"Odd:"<<odd<<endl;
	// cout<<"11%*56:"<<11%*56<<endl;
	return 0;
}