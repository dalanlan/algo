

//Excel Sheet Column Number
//base transformation
#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int titleToNumber(string s)
{
	int res = 0;
	for(int i=s.length()-1;i>=0;i--)
	{	
		//cout<<s[i]<<endl;
		res += pow(26,s.length()-1-i) * (s[i]-'A'+1) ;
		//cout<<pow(26,s.length()-1-i) * (s[i]-'A'+1) <<endl;
		
	}
	return res;
}

int main()
{
	string s("B");
	cout<<titleToNumber(s);
}