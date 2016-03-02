

/*
LintCode: combination sum

*/

class Solution {
public:
    /**
     * @param candidates: A list of integers
     * @param target:An integer
     * @return: A list of lists of integers
     */
    void combinationSum(vector<int> &cand, int target, vector<vector<int> > &res, vector<int> &path, int index, int sum) {
        if(sum == target) {
            res.push_back(path);
            return;
        }
        
        // This is a small trick
        // This is important, when to break
        // when to skip
        // can be reused for unlimited times
        int prev = -1;
        for(int i=index; i<cand.size(); i++) {
            if(sum + cand[i] > target) {
                break;
            }
            // to make it faster, which does not affect the result
            if(prev != -1 && cand[i] == prev) {
                continue;
            }
            path.push_back(cand[i]);
            combinationSum(cand, target, res, path, i, sum+cand[i]);
            path.pop_back();
            
            prev = cand[i];
            
            
        }
    }
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // write your code here
        
        vector<vector<int> > res;
        if(candidates.size() == 0 || target <=0) {
            return res;
        }
        
        vector<int> path;
        sort(candidates.begin(), candidates.end());
        combinationSum(candidates, target, res, path, 0, 0);
        return res;
        
    }
};


// solution 2: with or without the trick
// the solution works

class Solution {
public:
    /**
     * @param candidates: A list of integers
     * @param target:An integer
     * @return: A list of lists of integers
     */
    void combinationSum(vector<int> &cand, int target, vector<vector<int> > &res, vector<int> &path, int index, int sum) {
        if(sum == target) {
            res.push_back(path);
            return;
        }
        
        // can be reused for unlimited times
        // int prev = -1;
        for(int i=index; i<cand.size(); i++) {
            if(sum + cand[i] > target) {
                break;
            }
            // if(prev != -1 && cand[i] == prev) {
            //     continue;
            // }
            if(i>index && cand[i] == cand[i-1]) {
                continue;
            }
            path.push_back(cand[i]);
            combinationSum(cand, target, res, path, i, sum+cand[i]);
            path.pop_back();
            
            // prev = cand[i];
            
            
        }
    }
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // write your code here
        
        vector<vector<int> > res;
        if(candidates.size() == 0 || target <=0) {
            return res;
        }
        
        vector<int> path;
        sort(candidates.begin(), candidates.end());
        combinationSum(candidates, target, res, path, 0, 0);
        return res;
        
    }
};