//calculate orthonormal basis
#include<iostream>
using namespace std;

int main() {
	double res;
	// Question 1
	//double x = -0.702, y=.117, z=.702;  //A
	double x = -.937, y = .312, z = .156;  //B:-0.000285714  
	//double x = -.288, y = -.49, z = .772; //C: nope
	//double x=-.857, y = .286, z = .429;
	double A = 2/(double)7, B = 3/(double)7, C=6/(double)7;

	res =  A*x + B*y + C*z;
	cout<<res<<endl;
	

	/*double x,y,z;
	double colA1 = 2/(double)7, colA2 = 3/(double)7, colA3 = 6/(double)7;
	double colB1 = 6/(double)7, colB2 = 2/(double)7, colB3 = -3/(double)7;
	x*x + y*y + z*z = 1;
	*/
	return 0;
}