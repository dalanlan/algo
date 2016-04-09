
/*
LeetCode: search for a range
https://leetcode.com/problems/search-for-a-range/
*/

vector<int> searchRange(vector<int>& nums, int target) {
	int sz = nums.size();
	vector<int> res{-1, -1};

	int lo = 0, hi = sz-1;
	while(lo < hi) {
		int mid = (lo+hi)/2;
		if(nums[mid] < target) {
			lo  = mid+1;
		}
		else {
			hi = mid;
		}
	}
	if (nums[lo] == target) {
		res[0] = lo;
	}
	else {
		return res;
	}
	hi = sz-1;

	while(lo < hi) {
		int mid = (lo+hi)/2+1;
		if(nums[mid] > target) {
			hi = mid-1;
		}
		else {
			lo=mid;
		}
	}
	res[1] = hi;
	return res;
	

}
// solution 2: AC, not so fast though
class Solution {
public:
    vector<int> expand(int index, vector<int> &nums,int target) {
        int left = index;
        while(left >0 && nums[left-1] == target) {
            left--;
        }
        int right = index;
        while(right<nums.size()-1 && nums[right+1] == target) {
            right++;
        }
        return vector<int>{left,right};
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        
        // binary search + expansion
        vector<int> res;
        
        int sz = nums.size();
        if(sz == 0) {
            return res;
        }
        int lo = 0, hi = sz-1;
        while(lo <= hi) {
            int mid = lo + ((hi-lo)>>1);
            if(target == nums[mid]) {
                return expand(mid, nums, target);
            }
            else if(target > nums[mid]) {
                lo = mid+1;
            }
            else {
                hi = mid-1;
            }
        }
        return vector<int>{-1,-1};
    }
};