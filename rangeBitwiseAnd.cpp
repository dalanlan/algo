
/*
LeetCode: bitwise of and of numbers range
https://leetcode.com/problems/bitwise-and-of-numbers-range/
*/

// kick out the right not common part
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        while(n > m) {
            n&=n-1;
        }
        return n;
    }
};


// solution 2: find out leftmost common part
    int rangeBitwiseAnd(int m, int n) {
        int move = 0;
        while(m!=n) {
            m >>= 1;
            n >>= 1;
            move++;
        }
        return m<<move;
    }