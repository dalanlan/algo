
/*

LeetCode: factor combinations

Problem:

Numbers can be regarded as product of its factors. For example, 

8 = 2 x 2 x 2;
  = 2 x 4.
Write a function that takes an integer n and return all possible combinations of its factors. 

Note: 

Each combination's factors must be sorted ascending, for example: The factors of 2 and 6 is [2, 6], not [6, 2]. 
You may assume that n is always positive. 
Factors should be greater than 1 and less than n.
 

Examples: 
input: 1
output: 

[]
input: 37
output: 

[]
input: 12
output:

[
  [2, 6],
  [2, 2, 3],
  [3, 4]
]
input: 32
output:

[
  [2, 16],
  [2, 2, 8],
  [2, 2, 2, 4],
  [2, 2, 2, 2, 2],
  [2, 4, 4],
  [4, 8]
]

*/


vector<vector<int> > getFactors(int n) {
	vector<vector<int>> res;
	vector<int> path;
	helper(res, n, path, 2);
	return res;
}
void helper(vector<vector<int>> &res, int n, vector<int>& path, int factor) {
	if(n == 1) {
		res.push_back(path);
	}
	else {
		for(int i=factor; i<=n; i++) {
			if(n % i == 0) {
				path.push_back(i);
				helper(res, n/i, path, i);
				path.pop_back();
			}
		}
	}
}
