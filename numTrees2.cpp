
/*
LintCode: unique binary search trees
http://www.lintcode.com/zh-cn/problem/unique-binary-search-trees/

*/

int numTrees(int n) {
	vector<int> num=vector<int>(n+1, 0);
	num[0] = 1;

	for(int i=1; i<=n; i++) {
		for(int j=0; j<i; j++) {
			num[i] += num[j]*num[i-1-j];
		}
	}
	return num[n];
}