
/*
LintCode: binary representation
http://www.lintcode.com/zh-cn/problem/binary-representation/
*/



class Solution {
public:
    /**
     *@param n: Given a decimal number that is passed in as a string
     *@return: A string
     */
     
    // different parts : for integer part and for decimal part (?)

string binaryRepresentation(string n) {
	int len = n.length();

	int dot=0;
	while(dot < len && n[dot] != '.') {
		dot++;
	}
	if(dot == len) {
		return parseInt(n);
	}
	else {
		string last = parseFloat(n.substr(dot+1, len-dot-1));
		if(last == "ERROR") {
			return "ERROR";
		}

		string first = parseInt(n.substr(0, dot));
		if(last == "0" || last == "") {
			return first;
		}
		return first+"."+last;

	}
	
}

// int part
// put higher digit on the right bit

string parseInt(string s) {
	if(s.length() == 0 || s == "0") {
		return "0";
	}

	string res;
	int num = stoi(s);

	while(num) {
		res = to_string(num%2) + res;
		num /= 2;
	}
	return res;
}

// cyclic fraction
// *2
string parseFloat(string s) {
	unordered_set<double> dict;
	string res;
	double d = stod("0."+s);

	while(d) {
		if(res.length() > 32 || dict.count(d) != 0) {
			return "ERROR";
		}
		dict.insert(d);
		d = d*2;
		if(d>=1) {
			res += "1";
			d -= 1;
		}
		else {
			res += "0";
		}
	}
	return res;
}
};
