
/*
LeetCode: sum of two integers
https://leetcode.com/problems/sum-of-two-integers/
*/

class Solution {
public:
    // iterative 
    int getSum(int a, int b) {
        while(b) {
            int _and = a & b;
            a = a^b;
            b = _and << 1;
        }
        return a;
    }
};


int getSum(int a, int b) {
	return b==0?a:getSum(a^b, (a&b)<<1);

}

// get abstract

int getSub(int a, int b) {
	return b==0?a:getSub(a^b, (~a^b)<<1);
}