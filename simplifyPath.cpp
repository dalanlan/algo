#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <sstream>
using namespace std;

// AC
vector<string> split(string str, char del) {
	vector<string> res;
	stringstream ss(str);
	string token;

	while(getline(ss, token, del)) {
		res.push_back(token);
	}
	return res;

}

string simplifyPath(string path) {
	
	deque<string> deq;

	// split the string
	// "/home/" ["home"]
	// "/a/./b/../../c/" ["a",".","b","..","..","c"]
	vector<string> pathSplit = split(path, '/'); 

	for(int i=0;i<pathSplit.size();i++) {
		if(pathSplit[i] == "." || pathSplit[i] == "") {
			continue;
		}
		else if(pathSplit[i] == "..") {
			if(!deq.empty()) {
				deq.pop_back();
			}
			else
				continue;
		}
		else {
			deq.push_back(pathSplit[i]);
		}
	}
	
	
	if(deq.empty()) {
		return "/";
	}
	string res;
	
	while(!deq.empty()) {
		res += "/";
		res += deq.front();
		
		deq.pop_front();
		
	}
	return res;

}

int main() {

	string str("/a/./b///../c/../././../d/..//../e/./f/./g/././//.//h///././/..///");
	cout<<simplifyPath(str)<<endl;
	return 0;
}
