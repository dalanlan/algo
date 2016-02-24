
/*
LintCode: combinations
http://www.lintcode.com/zh-cn/problem/combinations/
*/

// solution : back-tracing
class Solution {
public:
    /**
     * @param n: Given the range of numbers
     * @param k: Given the numbers of combinations
     * @return: All the combinations of k numbers out of 1..n
     */
    
    void combine(vector<vector<int> > &res, vector<int> &path, int n, int k, int index) {
        if(path.size() == k) {
            res.push_back(path);
            return;
        }
        
        for(int i=index; i<=n; i++) {
            path.push_back(i);
            combine(res, path, n, k, i+1);
            path.pop_back();
        }
        
    }
    vector<vector<int> > combine(int n, int k) {
        // write your code here
        vector<vector<int> > res;
        vector<int> path;
        combine(res, path, n, k, 1);
        return res;
        
    }
};