
/*
LeetCode: 3Sum Smaller

Given an array of n integers nums and a target, find the number of index triplets i, j, k with 0 <= i < j < k < n that satisfy the condition nums[i] + nums[j] + nums[k] < target.
For example, given nums = [-2, 0, 1, 3], and target = 2.
Return 2. Because there are two triplets which sums are less than 2:
[-2, 0, 1]
[-2, 0, 3]
Follow up:
Could you solve it in O(n2) runtime?
*/

int threeSumSmaller(vector<int> nums, int target) {
	if(nums.size() < 3) {
		return 0;
	}
	sort(nums.begin(), nums.end());
	int count = 0;
	for(int i=0; i<nums.size()-2; i++) {
		// you dont want to skip the duplicate
		// cause they count
		threeSumSmaller(nums, target, count, i);
	}
	return count;
}

void threeSumSmaller(vector<int> nums, int target, int& count, int i) {
	int lo = i+1, hi = nums.size()-1;
	while(lo < hi) {
		int sum = nums[i] + nums[lo] + nums[hi];
		if(sum < target) {
			count+=hi-lo;
			lo++;
		}
		else {
			hi--;
		}

	}
}


// rewrite the previous solution
// we can actually pin the two segments together, right

int threeSumSmaller(vector<int> nums, int target) {
	if(nums.size() < 3) {
		return 0;
	}
	int count = 0;
	for(int i=0; i<nums.size()-2; i++) {
		int lo = i+1;
		int hi = nums.size()-1;
		while(lo < hi) {
			if(nums[lo]+nums[hi] + nums[i] < target) {
				count+=hi-lo;
				lo++;
			}
			else {
				hi--;
			}
		}
	}
	return count;
}
/*
3sum 
For backup
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size() < 3) {
            return res;
        }
        
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<nums.size()-2; i++) {
            if(i>0 && nums[i] == nums[i-1]) {
                continue;
            }
            twoSum(nums, res, i);
        }
        return res;
    }
    
    void twoSum(vector<int>& nums, vector<vector<int>>& res, int i) {
        
        int lo = i+1, hi = nums.size()-1;
        while(lo < hi) {
            int sum = nums[lo] + nums[hi];
            if(sum == -nums[i]) {
                res.push_back({nums[i], nums[lo], nums[hi]});
                do {
                    lo++;
                }while(lo<hi && nums[lo] == nums[lo-1]);
                
                do{
                    hi--;
                }while(lo<hi && nums[hi] == nums[hi+1]);
            }
            else if(sum < -nums[i]) {
                lo++;
            }
            else {
                hi--;
            }
        }
    }
};