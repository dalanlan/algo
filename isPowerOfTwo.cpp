//shift 
//transform to 2-base int 

#include <iostream>

using namespace std;


bool isPowerOfTwo(int n){
	
  int count = 0;
      unsigned int flag = 1;
      while(flag)
      {
            if(n & flag)
                  count ++;

            flag = flag << 1;
      }

      if( count==1)
      	return true;
      else
      	return false;
      


	// int count = 0;
	// while(n)
	// {
	// 	count++;
	// 	n=(n-1)&n;
	// }
	// if(count != 1)
	// 	return false;
	// else
	// 	return true;
}
int main()
{
	int n;
	cin>>n;
	cout<<isPowerOfTwo(n);

}