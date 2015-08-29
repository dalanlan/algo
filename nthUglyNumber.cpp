#include <iostream>
using namespace std;


int nthUglyNumber(int n) {
    
    if(n==1)
        return 1; 
    int *v = new int[n];       
    n--;
    int pos1=0, pos2=0, pos3=0;
    int can1, can2, can3, cur;
 
    
    v[0] = 1;
    int count=1;
    
    while(n)
    {
        can1=v[pos1]*2;
        can2=v[pos2]*3;
        can3=v[pos3]*5;
        cur=min(can1,min(can2,can3));
  

        if(cur == can1)
            pos1++;
        if(cur == can2)
            pos2++;
        if(cur == can3)
            pos3++;
        n--;
        v[count]=cur;
        count++;

    }

    return cur;
}


int main()
{
	cout<<nthUglyNumber(7)<<endl;
	return 0;
}