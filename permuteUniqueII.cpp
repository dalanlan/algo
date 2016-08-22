
/*
LintCode: permutations ii
permutations with dup
http://www.lintcode.com/zh-cn/problem/permutations-ii/
*/

class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: A list of unique permutations.
     */
    
    vector<vector<int> > permuteUnique(vector<int> &nums) {
        vector<vector<int> > res;
        if(nums.size() == 0) {
            return res;
        }
        sort(nums.begin(), nums.end());
        vector<int> path;
        vector<int> visited = vector<int>(nums.size(), 0);
        permute(res, path, visited, nums);
        return res;
    }
    
    void permute(vector<vector<int> > &res, vector<int> &path, vector<int> &visited, vector<int> &nums) {
        if(path.size() == nums.size()) {
            res.push_back(path);
            return;
        }
        for(int i=0; i<nums.size(); i++) {
            if(visited[i] == 1 || i >0 && nums[i] == nums[i-1] && visited[i-1] == 0) {
                continue;
            }
            path.push_back(nums[i]);
            visited[i] = 1;
            permute(res, path, visited, nums);
            visited[i] = 0;
            path.pop_back();
        }
    }
    };


// solution 2: 
   vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        // sort is to guarantee the comparison between 
        // the former one and the latter one
        sort(nums.begin(), nums.end());
        permute(res, nums, 0);
        return res;
    }
    void permute(vector<vector<int>> &res, vector<int> nums, int ind) {
        if(ind == nums.size()-1) {
            res.push_back(nums);
        }
        else {
            for(int i=ind; i<nums.size(); i++) {
                if(i!=ind && nums[i]==nums[ind]) {
                    continue;
                }
                swap(nums[i], nums[ind]);
                permute(res, nums, ind+1);
                
            }
        }
    }