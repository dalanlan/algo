
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

  //  vector<int> v1={};
    if(rowIndex<0)
    	return vector<int>();
		//return v1;
	vector<int> v(1,1);
	vector<int> vNext={};
	while(rowIndex != 0)
	{
		vNext={};
		for(int i=0;i<v.size()-1;i++)
			vNext.push_back(v[i]+v[i+1]);
		vNext.push_back(1);
		vNext.insert(vNext.begin(),1);
		v = vNext;
		rowIndex--;

	}
	return v;
}   // User less space then above;

//Here is an easy way
vector<int> getRow(int rowIndex) {
    vector<int> ans;
    int pre, tmp;
    for (int i = 0;i <= rowIndex;++i) {
        pre = 0;
        for (int j = 0;j < i;++j) {
            tmp = ans[j];
            ans[j] += pre;
            pre = tmp;
        }
        ans.push_back(1);
    }
    return ans;
}


int main()
{
	vector<vector<int> > res = generate(4);
	return 0;
}