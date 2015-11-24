// 4Sum

/* TLE

*/
    void find(vector<int>& nums, vector<int>& path, vector<vector<int>>& res, int target, int index, int cand) {
            for(int i=index;i<nums.size();i++) {
            if(cand == 0) {
                return;
            }
            if(nums[i] == target && cand == 1) {
                path.push_back(nums[i]);
                res.push_back(path);
                path.pop_back();
                
                return;
                
            }
            else if(cand > 1) {
                path.push_back(nums[i]);
                find(nums, path, res, target-nums[i],i+1,cand-1);
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
          // res.push_back(vector<int>{prev1, prev2, nums[lo],nums[hi]});

   				while(lo+1 < nums.size() && nums[lo] == nums[lo+1]) lo++;
   				while(hi-1 > -1 && nums[hi] == nums[hi-1]) hi--;

   			}
        //take care !!!!!! 
        // no "else"
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

    // Put the entire workflow all together
   vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int sz = nums.size();
        if(sz < 4) {
          return res;
        }

        sort(nums.begin(), nums.end());

        for(int i=0; i < sz-3; i++) {
            if(i > 0 && nums[i] == nums[i-1]) {
              continue;
            }
            if(nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target) {
              break;
            }
            if(nums[i] + nums[sz-3]+ nums[sz-2] + nums[sz-1] < target) {
              continue;
            }

            for(int j=i+1; j < sz-2; j++) {
                if(j > i+1 && nums[j] == nums[j-1]) {
                  continue;
                }
                if(nums[i] + nums[j] + nums[j+1] + nums[j+2] > target) {
                  break;
                }
                if(nums[i] + nums[j] + nums[sz-2] + nums[sz-1] < target) {
                  continue;
                }

                int lo = j+1, hi = sz-1, sum;
                while(lo < hi) {
                  sum = nums[i] + nums[j] + nums[lo] + nums[hi];
                  if(sum == target) {
                    res.push_back(vector<int>{nums[i], nums[j], nums[lo], nums[hi]});
                    lo++;
                    while(lo+1 < sz && nums[lo] == nums[lo-1]) {
                        lo++;
                    }
                    hi--;
                    while(hi-1 > -1 && nums[hi] == nums[hi+1]){
                        hi--;
                    }
                  } 
                  else if(sum < target) {
                    lo++;
                  }
                  else {
                    hi--;
                  }
                }
            }
        }
        return res;
    }