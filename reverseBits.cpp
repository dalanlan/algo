
//Reverse Bits
#include <iostream>
#include <stdint.h>
#include <algorithm>
#include <math.h>
using namespace std;

// solution1:
 
   uint32_t reverseBits(uint32_t n) {
       uint32_t m=0;
       
       for(int i=0; i<32; i++, n>>=1) {
           m <<= 1;
           m |= (n&1);
       }
       return m;
   } 

// solution 2:
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