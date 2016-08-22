class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> sol;
        combinationSum3(res, sol, k, n);
        return res;
    }
    
    void combinationSum3(vector<vector<int>> &res, vector<int> &sol, int k, int n) {
        if(sol.size() == k && n == 0) {
            res.push_back(sol);
        }
        else {
            for(int i= sol.empty()?1:sol.back()+1; i<=n && i <= 9; i++) {
                sol.push_back(i);
                combinationSum3(res, sol, k, n-i);
                sol.pop_back();
            }
        }
        
    }
};