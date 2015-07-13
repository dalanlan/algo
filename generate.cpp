
//Pascal's Triangle II
// what is Pascal's Triangle II

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generate(int numRows)
{

	vector<vector<int>> res;

	if(numRows <= 0)
		return res;

	vector<int> v (1,1); // the first row
	vector<int> vNext(2,1); // [1,1]
	res.push_back(v);
	numRows--;
	while(numRows != 0)
	{
		res.push_back(vNext);
		numRows--;
		v = vNext; // v:[1,1]
		vNext.clear();
		for(int i=0;i<v.size()-1;i++)
			vNext.push_back(v[i]+v[i+1]);
		vNext.push_back(1);
		vNext.insert(vNext.begin(),1);
	}
	return res;

}

int main()
{
	// vector<int> first;
	// first.push_back(1);
	// first.push_back(2);
	// for(int i =0 ;i< first.size(); i++)
	// 	cout<<first[i]<<endl;
	// std::vector<int> v(2,1);
	vector<std::vector<int> > v = generate(4);
	

	return 0;	
}