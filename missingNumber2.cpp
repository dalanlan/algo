/*
Leetcode:
https://leetcode.com/problems/missing-number/

Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

For example,
Given nums = [0, 1, 3] return 2.
*/


class Solution {
public:
    int missingNumber(vector<int>& A) {
        for(int i=0; i<A.size(); i++) {
            while(A[i] < A.size() && A[i]!=i) {
                swap(A[A[i]], A[i]);
            }
        }
        for(int i=0; i<A.size(); i++) {
            if(A[i] != i) {
                return i;
            }
        }
        return A.size();
    }
};