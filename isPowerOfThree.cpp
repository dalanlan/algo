
/*
LeetCode : power of three

https://leetcode.com/problems/power-of-three/
*/
    bool isPowerOfThree(int n) {
        return fmod(log10(n)/log10(3), 1) == 0;
    }