
/*
LintCode: gray code
http://www.lintcode.com/zh-cn/problem/gray-code/#

*/

class Solution {
public:
    /**
     * @param n a number
     * @return Gray code
     */
    vector<int> grayCode(int n) {
        
        // mirror operation
        // recursive
        vector<int> res;
        if(n == 0) {
            res.push_back(0);
            return res;
        }
        res = grayCode(n-1);
        int num;
        for(int i=res.size()-1; i>=0; i--) {
            num = res[i];
            num += (1 << (n-1));
            res.push_back(num);
        }
        return res;
        
    }
};