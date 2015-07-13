
//Pascal's Triangle

//Given an index k, return the kth row of the Pascal's triangle.
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > generate(int numRows)
{
	vector<vector<int> > res;
	for(int i=0;i<numRows;i++)
	{
		res.push_back(vector<int>(i+1,1));
		for(int j=1;j<i;j++)
			res[i][j] = res[i-1][j] + res[i-1][j-1];
	}	

	for(int i = 0;i<numRows;i++)
	{
		for(int j=0;j<=i;j++)
			cout<<res[i][j]<<' ';
		cout<<endl;
	}	
	return res;
}
vector<int> getRow(int rowIndex) 
{
	vector<vector<int> >res = generate(rowIndex+1);
	return res[rowIndex];

}   

vector<int> getRow(int rowIndex)
{
	
}

int main()
{
	vector<vector<int> > res = generate(4);
	return 0;
}