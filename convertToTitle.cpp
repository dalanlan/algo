

//Excel Sheet Column Title

#include <iostream>
#include <string>
using namespace std;

string convertToTitle(int n)
{
	string s;
	while(n)
	{	
		int rem = n%26;  //0~25      27 = 1 + 26^1 * 1 (AA)
		if(rem==0) 
			rem = 26;
		string str;
		 str += rem+'A'-1;
		s =str + s ; // 27%26 = 1; 27-1 = 26;
		n -= rem;
		n/= 26;

	}
	return s;
}

int main()
{
	cout<<convertToTitle(1);
	return 0;
}