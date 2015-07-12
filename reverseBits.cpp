
//Reverse Bits
#include <iostream>
#include <stdint.h>
#include <algorithm>
#include <math.h>
using namespace std;

uint32_t reverseBits(uint32_t n) {
      
    	char str[32],str2[32];
	int pos = 0;
	uint32_t ans = 0;

	for(int i=31;i>=0;i--)
	{
		if(n & (1<<i))
		{
			str[pos] = '1'; 
			ans += (1<<(31-i));//pow(2,pos);
		}	
		else
			str[pos] = '0';
		cout<<str[pos];
		
		pos++;

	}
	cout<<endl<<pos<<endl;
	cout<<"Ans2: "<<ans<<endl;
	uint32_t res = 0;
	for(int i =0;i<32;i++)
		res +=(uint32_t)pow(2,i) * (str[i]-'0');
	return res;

	
    }
int main()
{
	//cout<<"hello world!"<<endl;
	cout<<"Ans: "<<reverseBits(1)<<endl;
	//cout<<endl;
	//reverseBits(1212);
	return 0;
}