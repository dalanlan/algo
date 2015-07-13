
//Count and Say
#include <iostream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

string readString(string str)
{
	string s("");
	
	int i = 0;
	stringstream ss;

	while(i<str.length())
	{
		int count = 0;
		while(str[i+1] == str[i])
		{
			i++;
			count++;
		}
		ss.str("");
		//ss.clear();	
		ss<<(count+1);
		//cout<<"cout:"<<count+1<<endl;
		string tmp;

		tmp = ss.str();
		//tmp = string(itoa(count+1));
		//cout<<"ss:"<<ss.str()<<endl;
		
		tmp += str[i];
		//cout<< "tmp2:"<<tmp <<endl;
		s += tmp;
		i++;
	}
	return s;
} // Highly appreciated.

string countAndSay(int n)
{
	string strInit("1");
	for(int i=0;i<n-1;i++)
		strInit = readString(strInit);
	return strInit;
}
	

int main()
{
	cout<<countAndSay(3);
	return 0;
}