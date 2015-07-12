//Count Primes
//Count the number of prime numbers less than a non-negative numbers,n

#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

// bool isPrime(int n)
// {
// 	for(int i=3;i<n/3;i++)
// 		if(n % i == 0)
// 			return false;
// 	return true;
// }
// int countPrimes(int n) 
// {	
// 	// n == 1,not-prime
// 	// n == 2 , prime    

// 	if(n<=1)
// 		return 0;
// 	if(n==2)
// 		return 1;

// 	int count = 1;
// 	for(int i=3;i<=n;i+=2)
// 		if(isPrime(i)) count++;
// 	return count;
// }// it's a right sol, but time limit exceeeded.

  int countPrimes2(int n) {
    
	bool flag[n];
	//0~n;
	
	flag[2]=true;
	for(int i =3;i<n;i+=2)
	{
		flag[i] = true; // even, not prime
		flag[i+1] = false;
	}
	for(int i=3;i<=sqrt(n);i+=2)
	{
		if(flag[i])
		{
			for(int j=2*i;j<n;j+=i)
				flag[j] = false;
		}
	}
	int count = 0;
	for(int i=2;i<n;i++)
		if(flag[i])
			count ++;
	return count;
}

int countPrimes(int n)
{
	int flag[n];
	memset(flag,0,sizeof(flag));

	for(int i=2;i*i<n;i++)
		if(flag[i]==0)
		{
			for(int j=i;j*i<n;j++)
				flag[i*j] = 1;
		}

	// for(int i=0;i<n;i++)
	// 	cout<< flag[i]<<' ';
	// 	cout<<endl;	
	int count =0 ;
	for(int i=2;i<n;i++)
		if(flag[i]==0)
			count++;
	return count;



}
int main()
{
	cout<< countPrimes(1500000)<<endl;
	cout<<countPrimes2(1500000)<<endl;
	return 0;
}