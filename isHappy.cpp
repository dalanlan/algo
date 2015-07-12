//Happy Number

#include <iostream>
#include <unordered_set>
using namespace std;

int countDigitSquareSum(int n)
{
	int sum = 0;
	while(n)
	{
		int a = n%10;
		sum += a*a;
		n /=10;
	}
	return sum;

}
bool isHappy(int n)
{
	unordered_set<int> mp;
	int res = n;
	while(x > 1)
	{
		x = countDigitSquareSum(res);
		if(x == 1)
			return true;
		else
			if(mp.find(x) != mp.end())
				return false;
			else
				mp.insert(res);
	}
	return true;

}

int main()
{
	cout<<isHappy(19)<<endl;
	return 0;
}