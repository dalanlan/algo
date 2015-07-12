
//Compare Version Numbers 
//If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.
//https://leetcode.com/problems/compare-version-numbers/

#include <string>
#include <iostream>
#include <string.h>
#include <vector>
#include <sstream>

using namespace std;
/*
vector<string> split(string s, char delim) {
    stringstream ss(s);
    string item;
    vector<string> tokens;
    while (getline(ss, item, delim)) {
        tokens.push_back(item);
    }
    return tokens;
}
int compareVersion(string version1, string version2)
{
	std::vector<string> v1 = split(version1,".");
	std::vector<string> v2 = split(version2,".");
	if (v1[0]==v2[0])
	{
		if(v1[1]>v2[1])
			return 1;
		else
			if(v1[1] == v2[1])
				return 0;
			else
				return -1;

	}
	else
		if(v1[0]>v2[0])
			return 1;
		else
			return -1;

}

*/
int compareVersion(string version1,string version2)
{
	char *v1 = strdup(version1.c_str());
	char *v2 = strdup(version2.c_str());
	cout<<v1<<endl;
	cout<<v2<<endl;
	char *v1_ele = strtok(v1,".");
	char *v2_ele = strtok(v2,".");
	
	cout<<"v1:";
	for(int i =0;i<sizeof(v1_ele);i++)
		cout<<v1_ele[i]<<' ';

	cout<<endl;
	cout<<"V2:";
	for(int i =0;i<sizeof(v2_ele);i++)
		cout<<v2_ele[i]<<' ';
	cout<<endl;

	v1_ele = strtok(NULL, ".");
	cout<<"v1:";
	for(int i =0;i<sizeof(v1_ele);i++)
		cout<<v1_ele[i]<<' ';

	cout<<endl;
	v2_ele = strtok(NULL, ".");
	cout<<"V2:";
	for(int i =0;i<sizeof(v2_ele);i++)
		cout<<v2_ele[i]<<' ';
	cout<<endl;
	
	return 0;
	// int res = strcmp(v1_ele,v2_ele);
	// if(res != 0)
	// 	return res;
	// else
	// {
	// 	cout<<v1_ele<<endl;
	// 	cout<<v2_ele<<endl;
	// 	if (v1_ele!= NULL && v2_ele != NULL)
	// 	{
	// 		v1_ele = strtok(NULL, ".");
	// 		cout<< v1_ele<<endl;
	// 		v2_ele = strtok(NULL, ".");
	// 		cout<<v2_ele<<endl;
	// 	}
		
	// 	res = strcmp(v1_ele,v2_ele);
	// 	return res;
	// }
	
	

}


int main()
{
	string str("1.2");
	string str2("1.5");

	cout<<compareVersion(str,str2);
	return 0;
}