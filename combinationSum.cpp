// Combination Sum
void sum(vector<int>& candidates, int target, int index, vector<vector<int>>& res, vector<int>& path) {
    for(int j = index; j < candidates.size(); j++) {
        if(candidates[j] > target)
            break;
        if(candidates[j] == target) {
            path.push_back(candidates[j]);
            res.push_back(path);
            path.pop_back();
            return;
        }
        else {
            path.push_back(candidates[j]);
            sum(candidates,target - candidates[j], j, res, path);
            path.pop_back();
        }
        
    }
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> res;
    
    vector<int> path;
    sort(candidates.begin(), candidates.end());
    sum(candidates, target, 0, res, path);

    return res;
    
}