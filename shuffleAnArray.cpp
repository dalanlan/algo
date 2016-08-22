vector<int> num;
    vector<vector<int>> sequence;
    Solution(vector<int> nums) {
        num = nums;
        mutate(nums, 0);
    }
    
    void mutate(vector<int>& nums, int ind) {
        if(ind == nums.size()-1) {
            sequence.push_back(nums);
        }
        else {
        
            for(int i=ind; i<nums.size(); i++) {
                swap(nums[i], nums[ind]);
                mutate(nums, ind+1);
                swap(nums[i], nums[ind]);
            }
        }
    }
    
    
    /** Resets the array to its original configuration and return it. */
    
    
    vector<int> reset() {
        return num;
    }
    
    /** Returns a random shuffling of the array. */
    
    vector<int> shuffle() {
        int sz = sequence.size();
        if(sz == 0) {
            return {};
        }
        /*
        vector<int> res=sequence[0];
        
        for(int i=1; i<=sz; i++) {
            if(rand()%i == 0) {
                res = sequence[i-1];
            }
        }*/

        return sequence[rand()%sz];
    }


    class Solution {
public:
    
    vector<int> num;
    Solution(vector<int> nums) {
        num = nums;
    }
    
    vector<int> reset() {
        return num;class Solution {
public:
    
    vector<int> num;
    Solution(vector<int> nums) {
        num = nums;
    }
    
    vector<int> reset() {
        return num;
    }
    
    vector<int> shuffle() {
        if(num.size() == 0) {
            return {};
        }
        vector<int> tmp(num);
        int sz = num.size();
        for(int i=0; i<sz; i++) {
            int j=sz-1-rand()%(sz-i);
            swap(tmp[i], tmp[j]);
        }
        return tmp;
    }
    
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */
    }
    
    vector<int> shuffle() {
        if(num.size() == 0) {
            return {};
        }
        vector<int> tmp(num);
        int sz = num.size();
        for(int i=0; i<sz; i++) {
            int j=sz-1-rand()%(sz-i);
            swap(tmp[i], tmp[j]);
        }
        return tmp;
    }
    
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */

 