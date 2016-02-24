
/*
LintCode: three sum closest
http://www.lintcode.com/zh-cn/problem/3sum-closest/
*/

class Solution {
public:    
    /**
     * @param numbers: Give an array numbers of n integer
     * @param target: An integer
     * @return: return the sum of the three integers, the sum closest target.
     */
    int threeSumClosest(vector<int> nums, int target) {
        // write your code here
        int numSum = 0;
        for(auto x:nums) {
            numSum += x;
        }
        if(nums.size() <= 3) {
            return numSum;
        }
        sort(nums.begin(), nums.end());
       
        int  sum=numSum;
        for(int i=0; i<nums.size()-2; i++) {
            if(i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            int tmp = nums[i] + twoSumClosest(nums, i+1, target-nums[i]);
            if(abs(sum - target) > abs(tmp-target)) {
                sum = tmp;
            }
            
           
        }
        return sum;
    }
    int twoSumClosest(vector<int> nums, int index, int target) {
        int sz = nums.size();
        int lo = index, hi = sz-1;
        int res = nums[lo]+nums[hi];
        while(lo < hi) {
            int sum = nums[lo] + nums[hi];
            if(sum == target) {
                return target;
            }
            else {
                if(abs(sum-target) <= abs(res-target)) {
                    res = sum;
                }
                
                if(sum < target) {
                    lo++;
                }
                else {
                    hi--;
                }
            }
        }
        return res;
    }
};


//solution 2: rewrite
// no particular algorithm

  int threeSumClosest(vector<int> nums, int target) {
  	if(nums.size() < 3) {
  		return INT_MAX;
  	}
  	int sz = nums.size();
  	sort(nums.begin(), nums.end());
  	int closest = nums[0]+nums[1]+nums[2];
  	for(int i=0; i<sz; i++) {
  		int left = i+1;
  		int right = sz-1;
  		while( left < right) {
  			int sum = nums[i] + nums[left] + nums[right];
  			if(sum == target) {
  				return target;
  			}
  			if(abs(closest- target) > abs(sum-target)) {
  				closest = sum;
  			}
  			if(sum < target) {
  				left++;
  			}
  			if(sum > target) {
  				right--;
  			}
  		}
  	}
  	return closest;
  }