
/*
LeetCode: generate parentheses
https://leetcode.com/problems/generate-parentheses/

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"

*/

vector<string> generateParenthesis(int n) {
	vector<string> res;
	generate(res, n, n, "");
	return res;
}

void generate(vector<string>& res, int left, int right, string path) {
	
	if(left == 0 && right == 0) {
		res.push_back(path);
	}

	if(left > 0) {
		generate(res, left-1, right, path+"(");
	}
	if(right > left) {
		generate(res, left, right-1, path+")");
	}
}