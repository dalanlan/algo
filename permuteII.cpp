/*
LintCode: permutations
http://www.lintcode.com/zh-cn/problem/permutations/
*/

class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: A list of permutations.
     */
    void permute(vector<vector<int>> &res, vector<int> &nums, int index) {
        if(index == nums.size()) {
            res.push_back(nums);
        }
        else {
            for(int i=index; i<nums.size(); i++) {
                swap(nums[i], nums[index]);
                permute(res, nums, index+1);
                swap(nums[i], nums[index]);
            }
        }
    }
    vector<vector<int> > permute(vector<int> nums) {
        vector<vector<int>> res;
        if(nums.size() == 0) {
            return res;
        }
        permute(res, nums, 0);
        return res;
    }
};


// rewrite: does not make much sense
void permute(vector<vector<int> > &res, vector<int> &nums, int index) {
        if(index == nums.size()) {
            res.push_back(nums);
            return;
        }
        for(int i=index; i<nums.size(); i++) {
            swap(nums[index], nums[i]);
            permute(res, nums, index+1);
            swap(nums[index], nums[i]);
        }
    }
    vector<vector<int> > permute(vector<int> nums) {
        vector<vector<int> >res;
        if(nums.size() == 0) {
            return res;
        }
        sort(nums.begin(), nums.end());
        

        permute(res, nums, 0);
        return res;
    }


    // solution 2: iterative

    vector<vector<int> > permute(vector<int> nums) {
        vector<vector<int> > res;
        if(nums.size() == 0) {
            return res;
        }
        
        res.push_back(vector<int>{});
        for(int i=0; i<nums.size(); i++) {
            vector<vector<int> > nextRes;
            for(auto &x: res) {
                for(int j=0; j<x.size()+1; j++) {
                    x.insert(x.begin()+j, nums[i]);
                    nextRes.push_back(x);
                    x.erase(x.begin()+j);
                }
            }
            res = nextRes;
        }
        return res;
    }