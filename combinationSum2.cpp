// Combination Sum II 
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
        sum(candidates,target - candidates[j], j+1, res, path);
        path.pop_back();
        while (j < candidates.size()-1 && candidates[j] == candidates[j+1]) j++;
    }
    
}
}
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> res;
    
    vector<int> path;
    sort(candidates.begin(), candidates.end());
    sum(candidates, target, 0, res, path);

    return res;
    
}