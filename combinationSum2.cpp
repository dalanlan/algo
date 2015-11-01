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

// Another solution, pretty similar
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {  
      // Start typing your C/C++ solution below  
      // DO NOT write int main() function  
      // Start typing your C/C++ solution below  
      // DO NOT write int main() function  
      vector<vector<int> > result;  
  vector<int> solution;  
  int sum=0;  
  std::sort(num.begin(), num.end());  
      GetCombinations(num,sum, 0, target, solution, result);  
      return result;  
    }  
    void GetCombinations(  
      vector<int>& candidates,  
      int& sum,  
      int level,  
      int target,  
      vector<int>& solution,  
      vector<vector<int> >& result)  
    {  
      if(sum > target) return;  
      if(sum == target)  
      {  
        result.push_back(solution);  
        return;  
      }  
      for(int i =level; i< candidates.size(); i++)  
      {  
        sum+=candidates[i];  
        solution.push_back(candidates[i]);  
        GetCombinations(candidates, sum, i+1, target, solution, result);  
        solution.pop_back();  
        sum-=candidates[i];    
        while(i<candidates.size()-1 && candidates[i] == candidates[i+1]) i++;  
      }  
    }
