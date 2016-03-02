
/*
LintCode: combinarion sum ii
http://www.lintcode.com/zh-cn/problem/combination-sum-ii/
*/

class Solution {
public:
	/**
	 * @param num: Given the candidate numbers
	 * @param target: Given the target number
	 * @return: All the combinations that sum to target
	 */
	
	void combinationSum(vector<int> &num, vector<vector<int> > &res, vector<int> &path, int target, int index) {
	    if(target == 0) {
	        res.push_back(path);
	        return;
	    }
	    for(int i=index; i<num.size(); i++) {
	        if(target < 0) {
	            break;
	        }
	        if(i > index && num[i] == num[i-1]) {
	            continue;
	        }
	       
	        path.push_back(num[i]);
	        combinationSum(num, res, path, target-num[i], i+1);
	        path.pop_back();
	    }
	}
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        // write your code here
        vector<vector<int> > res;
        
        if(target <=0 || num.size() ==0) {
            return res;
        }
        
        sort(num.begin(), num.end());
        vector<int> path;
        combinationSum(num, res, path, target, 0);
        return res;
        
        
    }
};