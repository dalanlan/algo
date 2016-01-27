/*
LintCode: generate parentheses 
http://www.lintcode.com/zh-cn/problem/generate-parentheses/
*/

class Solution {
public:
    /**
     * @param n n pairs
     * @return All combinations of well-formed parentheses
     */
    void helper(vector<string> &res, string paren, int left, int right) {
        if(left == 0 && right == 0) {
            res.push_back(paren);
            return;
        }
        if(left > 0) {
            helper(res, paren+"(", left-1, right);
        }
        if(right > 0 && right > left) {
            helper(res, paren+")", left, right-1);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        if(n == 0) {
            return res;
        }
        
        helper(res, "", n, n);
        return res;
    }
};