
/*
LintCode: k sum II

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


    void helper(vector<vector<int> > &res, vector<int> &A, int k, vector<int> &path, int target, int index) {
    	   	
    	if(target == 0) {
    		res.push_back(path);
    	}
    	path.push_back(A[i]);
    	


    }
    vector<vector<int> > kSumII(vector<int> A, int k, int target) {
    	vector<vector<int> > res;
    	if(A.size() == 0) {
    		return res;
    	}    
    	for(int i=0; i<A.size(); i++) {
    		if(target >= A[i]) {
    			vector<int> path{};
    			helper(res, A, k, path, target, i);
    		}
    	}
    	return res;

    }
};