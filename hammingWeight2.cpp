
/*
LeetCode: number of 1 bits
https://leetcode.com/problems/number-of-1-bits/
*/

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while(n) {
            count += n&1;
            n >>= 1;
        }
        return count;
    }
};


// soooo brilliant idea
    int hammingWeight(uint32_t n) {
        int count = 0;
        while(n) {
            n &= n-1;
            count++;
        }
        return count;
    }