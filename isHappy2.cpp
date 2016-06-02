
/*

LeetCode: happy number
https://leetcode.com/problems/happy-number/

Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

*/


// solution 1: naive method
class Solution {
public:
    int flatten(int n) {
        int res = 0;
        while(n) {
            int tmp = n%10;
            res += tmp*tmp;
            n /= 10;
        }
        return res;
    }
    bool isHappy(int n) {
        unordered_set<int> cache;
        if(n == 1) {
            return true;
        }
        
        while(n != 1) {
            int x = flatten(n);
            if(cache.count(x) > 0) {
                return false;
            }
            cache.insert(x);
            n = x;
        }
        return true; 
    }
};


// solution 2: 
// floyd cycle detection

    int flatten(int n) {
        int res = 0;
        while(n) {
            int tmp = n%10;
            res += tmp*tmp;
            n /= 10;
        }
        return res;
    }
    
    bool isHappy(int n) {
        int slow = n;
        int fast = n;
        
        do {
            slow = flatten(slow);
            fast = flatten(fast);
            fast = flatten(fast);
            
        } while(slow != fast);
        return slow == 1;
    }


// solution 3: let's do the math
    
