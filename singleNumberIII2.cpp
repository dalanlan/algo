
/*
LintCode : Single Number III
*/

vector<int> singleNumberIII(vector<int> &A) {
	int res = 0;
	for(int i=0; i<A.size(); i++) {
		res ^= A[i];
	}
	int pos = 0;
	while(!(res >> pos & 1)) {
		pos++;
	}
	int res1 = 0;
	int res2 = 0;
	for(int i=0;i<A.size(); i++) {
		if(A[i] >> pos & 1) {
			res1 ^= A[i];
		}
		else {
			res2 ^= A[i];
		}
	}
	vector<int> ans;
	ans.push_back(res1);
	ans.push_back(res2);
	return ans;
}