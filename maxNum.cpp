
/*
Leetcode: create maximum number
https://leetcode.com/problems/create-maximum-number/
*/

class Solution {
public:
    
    // find out the maximum array with a bunch of vector elements
    // maximum length k
    vector<int> maxNum(vector<int> nums, int k) {
        
        vector<int> res(k, 0);
        int i, j;
        int n = nums.size();
        for(i=0, j=0; i<n; i++) {
            while(n-i+j>k && j>0 &&nums[i] > res[j-1]) {
                j--;
            }
            if(j<k) {
                res[j++] = nums[i];
            }
        }
        return res;
    }
    
    // find out the max array with two given arrays 
    // while k is the sum of the length of the two arrays
    vector<int> maxNum(vector<int>& nums1, vector<int>& nums2) {
        int sz1 = nums1.size();
        int sz2 = nums2.size();
        int k=sz1+sz2;
        vector<int> res(k, 0);
        for(int i=0, j=0, r=0; r<k; r++) {
            if(greater(nums1, i, nums2, j)) {
                res[r] = nums1[i++];
            }
            else {
                res[r] = nums2[j++];
            }
        }
        return res;
    }
    
    bool greater(vector<int> num1, int ind1, vector<int> num2, int ind2) {
        while(ind1 < num1.size() && ind2 < num2.size() && num1[ind1] == num2[ind2]) {
            ind1++;
            ind2++;
        }
        return ind2==num2.size() || (ind1 < num1.size() && num1[ind1] > num2[ind2]);
    }
    
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int sz1 = nums1.size();
        int sz2 = nums2.size();
        vector<int> ans(k, 0);
        
        for(int i=max(0, k-sz2); i<=k && i<=sz1; i++) {
            vector<int> cand1 = maxNum(nums1, i);
            vector<int> cand2 = maxNum(nums2, k-i);
            vector<int> candidate = maxNum(cand1, cand2);
            if(greater(candidate, 0, ans, 0)) {
                ans = candidate;
            }
        }
        return ans;
    }
};