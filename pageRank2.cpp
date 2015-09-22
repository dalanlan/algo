// Page Rank

#include<iostream>
#include<cmath>
using namespace std;

//Question 1
int main(){
	

	double Small = 1e-20;
	
	double res[500][3];
	//initialize
	for(int pos = 0;pos<3;pos++)
	{
		res[0][pos] = (double)1/3;
	}	

	

	int t = 1;
	do {
		double aTmp = 0.85*(res[t-1][2]);
		double bTmp = 0.85*res[t-1][0]*0.5;
		double cTmp = 0.85*(res[t-1][0]*0.5+res[t-1][1]);
		//cout << aTmp<< " "<<bTmp<<" "<<cTmp<<endl;
		double S = aTmp + bTmp + cTmp;
		double leak = (3-S)/3;

		res[t][0] = aTmp + leak;
		res[t][1] = bTmp + leak;
		res[t][2] = cTmp + leak;
		t++;
		//cout<<abs(res[t][0] - res[t-1][0])<<endl;
		//cout<<abs(res[t-1][0] - res[t-2][0])<<endl;
		//cout<<res[t-1][1] - res[t-2][1]
		
	} while(abs(res[t-1][0] - res[t-2][0]) > Small && abs(res[t-1][1] - res[t-2][1]) > Small && abs(res[t-1][2] - res[t-2][2]) > Small);

	cout<<t<<endl;
	cout<<res[t-1][0]<<" "<<res[t-1][1] <<" "<<res[t-1][2] <<endl;
	cout<<"sum="<<res[t-1][0]+res[t-1][1]+res[t-1][2] <<endl;
	/*cout<<"b+c="<<res[t-1][1] + res[t-1][2]<<endl;
	cout<<"a+c="<<res[t-1][0] + res[t-1][2]<<endl;
	cout<<"a+b="<<res[t-1][0] + res[t-1][1]<<endl;*/
	cout<<abs(res[t-1][0] -(res[t-1][2] + 0.15*res[t-1][1]))<<endl;
	cout<<abs(res[t-1][0] -(0.9*res[t-1][2] + 0.05*res[t-1][1]))<<endl;
	cout<<abs(0.85*res[t-1][2] - (res[t-1][1] + 0.575*res[t-1][0]))<<endl;
	cout<<abs(0.95*res[t-1][0] - (0.9*res[t-1][2] + 0.05*res[t-1][1]))<<endl;

	if(res[t-1][0] == res[t-1][2] + 0.15*res[t-1][1])
		cout<<"A"<<endl;
	if(res[t-1][0] == 0.9*res[t-1][2] + 0.05*res[t-1][1])
		cout<<"B"<<endl;
	if(0.85*res[t-1][2] == res[t-1][1] + 0.575*res[t-1][0])
		cout<<"C"<<endl;
	if(0.95*res[t-1][0] == 0.9*res[t-1][2] + 0.05*res[t-1][1])
		cout<<"D"<<endl;
	return 0;

}