
//Factorial Trailing Zeros
#include <iostream>
using namespace std;

int trailingZeroes(int n)
{
	int count = 0;
	n /= 5;
	while(n)
	{
		count+=n;
		n/=5;

	}
	return count;
}
int main()
{
	cout<<trailingZeroes(25)<<endl;
	return 0;
}