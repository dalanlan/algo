//Summary Ranges
/*
Given a sorted integer array without duplicates, return the summary of its ranges.

For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].

*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;

 
//Summary Ranges


vector<string> summaryRanges(vector<int>& nums)
{
	vector<string> res;
	if(nums.empty()) // special case
		return res;
		//return ;
	std::vector<int>::iterator it = nums.begin();
	while(it != nums.end())
	{
		//cout<<*it<<endl;
		std::vector<int>::iterator pos=it;
		std::vector<int>::iterator pos1 = it++;
		while(it!= nums.end() && (*it- *pos1 == 1))
		{
			it++; // pos1+1
			pos1++;// original
		}
		//cout<<*pos<<endl;
		//cout<<*it<<endl;
		//cout<<*pos1<<endl;
		//cout<<(*it)<<'  '<<(*pos1)<<endl;
		
		//stringstream ss;
		string ele;
		if( *pos != *pos1)
		{
			char b[20],c[20];
			int length = sprintf(b,"%d",*pos);
			length = sprintf(c,"%d",*pos1);
			
			string s1 =b;
			string s2 =c;
			/*ss<<(*pos);
			string s1 = ss.str();
			ss<<(*pos1);
			string s2 = ss.str();
			*/
			ele =   s1+ "->" + s2 ;
		}	
		else
		{
		    char b[20];
		    int length2 = sprintf(b,"%d",*pos);
		    string s3 = b;
			//ss<<(*pos);
			//string s3 = ss.str();
			ele =  s3 ;
			
		}
		res.insert(res.end(),ele);
		
	}
	return res;
	
}	

}
int main()
{
	int a[] = {0,1,2,4,5,7};
	std::vector<int> v(a,a+sizeof(a)/sizeof(int));
	summaryRanges(v);
	//for(vector<string>::iterator it = res.begin(); it != res.end();it++)
	//	cout<<*it<<endl;

}


vector<string> summaryRanges(vector<int>& nums) {
	vector<string> res;

	int sz = nums.size();
	int beginIdx = 0, endIdx = 0;
	while(endIdx < sz) {
		while(endIdx+1<sz && nums[endIdx+1] == nums[endIdx]+1) {
			endIdx++;
		}
		if(beginIdx == endIdx) {
			res.push_back(to_string(nums[beginIdx]));
		}
		else {
			res.push_back(to_string(nums[beginIdx]) + "->" + to_string(nums[endIdx]));
		}
		beginIdx = endIdx+1;
		endIdx = beginIdx;
	}
	return res;
}