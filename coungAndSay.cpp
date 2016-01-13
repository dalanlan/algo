/*

420: Count numbers

1, 11, 21, 1211, 111221, ...

1 读作 "one 1" -> 11.

11 读作 "two 1s" -> 21.

21 读作 "one 2, then one 1" -> 1211.

给定一个整数 n, 返回 第 n 个顺序。

*/

string countAndSay(int n) {
	
	//initialization
	string res="1";
	
	for(int i=1; i<n; i++) {
		string tmp;
		int p=0;
		while(p < res.size()) {
			int q = p;
			while(q+1 < res.size() && res[q+1] == res[p]) {
				q++;
			}
			tmp += to_string(q-p+1) + res[p];
			p = q+1;
		}
		res = tmp;
	}
	return res;
}