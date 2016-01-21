
/*
LintCode : product of array exclude itself 
给定一个整数数组A。

定义B[i] = A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1]， 计算B的时候请不要使用除法。
*/


class Solution {
public:
    /**
     * @param A: Given an integers array A
     * @return: A long long array B and B[i]= A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1]
     */
    vector<long long> productExcludeItself(vector<int> &nums) {
        vector<long long> res(nums.size(),1);
        long long left=1, right=1;
        for(int i=1; i<nums.size(); i++) {
        	left *= nums[i-1];
        	res[i] *= left;
        }
        for(int i=nums.size()-2; i>=0; i--) {
        	right *= nums[i+1];
        	res[i] *= right;
        }
        return res;

    }
};