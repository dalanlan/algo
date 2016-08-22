
/*
LeetCode: super pow
https://leetcode.com/problems/super-pow/
*/

/*
idea:
One knowledge: ab % k = (a%k)(b%k)%k
Since the power here is an array, we'd better handle it digit by digit.
One observation:
a^1234567 % k = (a^1234560 % k) * (a^7 % k) % k = (((a^123456) % k) ^ 10 ) % k * a^7 % k
Looks complicated? Let me put it other way:
Suppose f(a, b) calculates a^b % k; Then translate above formula to using f :
f(a,1234567) = f(a, 1234560) * f(a, 7) % k = f(f(a, 123456),10) * f(a,7)%k;
*/

class Solution {
public:
    
    // b is no greater than 10
    int powMode(int a, int b) {
        int res = 1;
        a %= 1337;
        for(int i=0; i<b; i++) {
            res = (res*a)%1337;
        }
        return res;
    }
    int superPow(int a, vector<int>& b) {
        if(b.empty()) {
            return 1;
        }
        int bak = b.back();
        b.pop_back();
        return powMode(superPow(a, b), 10)*powMode(a, bak)%1337;
    }
};