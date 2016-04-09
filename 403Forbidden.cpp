

// 403 forbidden

#include<string>
#include<vector>
#include<iostream>

using namespace std;

string decimalTobinary(int val) {
	string res;
	for(int i=7; i>=0; i--) {
		if (val & (1<<i)) {
			res += "1";
		}
		else {
			res += "0";
		}
	}
	return res;
}
string convertor(string &s) {
	int len = s.length();
	string res;
	int start = 0, end = start;
	while(end < len) {
		while(s[end] != '.') {
			end++;
		}
		int cut = stoi(s.substr(start, end-start));
		
		res+=decimalTobinary(cut);
		start = end+1;
		end = start;
	}
	return res;
}

// is match
int isMatch(string& request, vector<pair<string,int> > &v) {
	string orig = convertor(request);
	//cout<<orig<<endl;
	for(int i=0; i<v.size(); i++) {
		if(request == v[i].first) {
			return v[i].second;
		}
		else {

			string ip = v[i].first;
			int found = ip.find('/');
			if(found != string::npos) {
				bool flag = true;
				string part = ip.substr(0, found);
				string cand = convertor(part);
				int mask = stoi(ip.substr(found+1));
				//cout<<mask<<endl;
				for(int j=0; j<mask; j++) {
					if(orig[j] != cand[j]) {
						flag = false;
					}
				}
				if(flag) {
					return v[i].second;
				}

			}
	}
	
	}
	return 1;
}
int main() {
	
	int n; // num of rules
	int m; // num of incoming request

	cin>>n>>m;
	//unordered_map<string, int> map;
	// false: deny
	// true: allow
	vector<pair<string,int> > v;
	for(int i=0; i<n; i++) {
		string acce;
		cin>>acce;
		string rule;
		cin>>rule;
		
		v.push_back(make_pair(rule, acce=="allow"?1:0));
		//cout<<v.back().first<<" "<<v.back().second<<endl;;

	}

	for(int i=0; i<m; i++) {
		string request;
		cin>>request;
		//cout<<request<<endl;
		if(isMatch(request, v) == 1) {
			cout<<"YES"<<endl;
		}
		else {
			cout<<"NO"<<endl;
		}

	}
	return 0;
}
