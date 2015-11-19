// 4Sum

/* Wrong solution
Test case: 
[1,0,-1,0,-2,2]
0

My answer:
[[-2,-1,1,2],[-2,-1,2,1],[-2,0,0,2],[-2,0,1,1],[-2,0,2,0],[-2,1,0,1],[-2,1,1,0],[-2,2,0,0],[-1,-1,0,2],[-1,-1,1,1],[-1,-1,2,0],[-1,0,0,1],[-1,0,1,0],[-1,1,0,0],[0,-1,0,1],[0,-1,1,0],[0,0,0,0],[1,-1,0,0]]

Expected answer:
[[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

*/
    void find(vector<int>& nums, vector<int>& path, vector<vector<int>>& res, int target, int index, int cand) {
            for(int i=index;i<nums.size();i++) {
            if(cand == 0)
                break;
            if(nums[i] == target && cand == 1) {
                path.push_back(nums[i]);
                res.push_back(path);
                path.pop_back();
                cand--;
                return;
                
            }
            else if(cand > 1) {
                path.push_back(nums[i]);
                find(nums, path, res, target-nums[i],index+1,cand-1);
                path.pop_back();
                while(i < nums.size()-1 && nums[i] == nums[i+1]) i++;
            }
            }
        
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> path;
       
        find(nums, path, res, target,0, 4);
        
        return res;
    }