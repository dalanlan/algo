
/*
LintCode: print numbers by recursion
http://www.lintcode.com/zh-cn/problem/print-numbers-by-recursion/
*/

class Solution {
public:
    /**
     * @param n: An integer.
     * return : An array storing 1 to the largest number with n digits.
     */
    vector<int> numbersByRecursion(int n) {
        // write your code here
        vector<int> res;
        if(n <= 0) {
            return res;
        }
        recursionUtil(n, res);
        return res;
    }
    int recursionUtil(int n, vector<int> &res) {
        if(n == 0) {
            return 1;    
        }
        int base = recursionUtil(n-1, res);
        int sz = res.size();
        
        for(int i=1; i<=9; i++) {
            int subBase = base*i;
            res.push_back(subBase);
            for(int i=0; i<sz; i++) {
                res.push_back(subBase + res[i]);
            }
        }
        return base*10;
    }
};