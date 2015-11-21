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



/* Supposed to be the right answer*/

       void twoSum(vector<int>& nums, vector<vector<int>>& res, int target, int index, int prev2, int prev1) {
    	if(index > nums.size()-2)
    		return;
    	int lo=index, hi=nums.size()-1, sum;
    	vector<int> path;

   		while(lo < hi) {
   			sum = nums[lo] + nums[hi];
   			if(sum == target) {
   				path.push_back(prev1);
   				path.push_back(prev2);
   				path.push_back(nums[lo]);
   				path.push_back(nums[hi]);
   				res.push_back(path);
   				path.clear();

   				while(lo+1 < nums.size() && nums[lo] == nums[lo+1]) lo++;
   				while(hi-1 > -1 && nums[hi] == nums[hi-1]) hi--;

   			}
   			if(sum < target)
   				lo++;
   			else 
   				hi--;
   		}
   		

    }

    void threeSum(vector<int>& nums, vector<vector<int>>& res, int target, int index, int prev) {
    	if(index > nums.size()-3)
    		return;
    	for(int i=index;i<nums.size();i++) {
    		if(i > index && nums[i] == nums[i-1]) continue;
    		twoSum(nums, res, target-nums[i], i+1, nums[i], prev);
    	}
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
    	vector<vector<int>> res;
    	if(nums.size() < 4)
    		return res;
        sort(nums.begin(), nums.end());
    	for(int i=0; i<nums.size();i++) {
    		if(i > 0 && nums[i] == nums[i-1]) continue;
    		threeSum(nums, res, target - nums[i], i+1, nums[i]);
    	}
    	return res;
    }


    /** Isn't there any convenient way? **/