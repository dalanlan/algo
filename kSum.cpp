
/*
LintCode: k sum ii
http://www.lintcode.com/zh-cn/problem/k-sum-ii/
*/
class Solution {
public:
    /**
     * @param A: an integer array.
     * @param k: a positive integer (k <= length(A))
     * @param target: a integer
     * @return a list of lists of integer 
     */
     
    void kSum(vector<vector<int> > &res, vector<int> &A, vector<int> &path, int k, int index, int target) {
        if(path.size() == k) {
            if(target == 0) {
                res.push_back(path);
            }
            // index == k
            return;
        }
        
        for(int i=index; i<A.size(); i++) {
            if(A[i] <= target) {
                path.push_back(A[i]);
                kSum(res, A, path, k, i+1, target - A[i]);
                path.pop_back();
            }
        }
    }
    vector<vector<int> > kSumII(vector<int> A, int k, int target) {
        vector<vector<int> > res;
        if(A.size() == 0 || k == 0 || target <= 0) {
            return res;
        }
        vector<int> path;
        kSum(res, A, path, k, 0, target);
        return res;
    }
};
